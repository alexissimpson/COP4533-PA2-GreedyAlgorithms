#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

map<string, queue<int>> handleInput(vector<string>& requests){
    map<string, queue<int>> requestIndices; // map [request, queue of indices]
    for(int i=0; i<requests.size(); i++){
        requestIndices[requests[i]].push(i);
    }
    return requestIndices;
}

void farthestInTheFuture(int k, vector<string> requests, ofstream& outfile) {
    map<string, queue<int>> requestIndices = handleInput(requests);
    set<string> cache;
    int numMisses = 0;

    for(string request : requestIndices){
        // remove current request index from its queue
        requestIndices[request].pop();

        if (!cache.count(request)){
            numMisses++;
            // check if cache is full
            if(cache.size() < k){
                cache.insert(request);
            } else{
                // find furthest request in the cache
                string remove;
                int farthest = -1;
                for(string data : cache) {
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