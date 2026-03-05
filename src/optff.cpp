#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

map<int, queue<int>> handleInput(vector<int>& requests){
    map<int, queue<int>> requestIndices; // map [request, queue of indices]
    for(int i=0; i<requests.size(); i++){
        requestIndices[requests[i]].push(i);
    }
    return requestIndices;
}

void farthestInTheFuture(int k, vector<int> requests, ofstream& outfile) {
    map<int, queue<int>> requestIndices = handleInput(requests);
    set<int> cache;
    int numMisses = 0;

    for(int request : requestIndices){
        // remove current request index from its queue
        requestIndices[request].pop();

        if (!cache.count(request)){
            numMisses++;
            // check if cache is full
            if(cache.size() < k){
                cache.insert(request);
            } else{
                // find furthest request in the cache
                int remove;
                int farthest = -1;
                for(int data : cache) {
                    queue<int> curRequests = requestIndices[data];
                    // if a request has no future use, break loop and remove it
                    if(curRequests.empty()){
                        remove = data;
                        break;
                    }
                    int nextRequest = curRequests.front();
                    if (nextRequest > farthest){
                        farthest = nextRequest;
                        remove = data;
                    }
                }
                cache.erase(remove);
                cache.insert(request);
            }

        }
    }

    outfile << "OPTFF: " << numMisses << endl;
}