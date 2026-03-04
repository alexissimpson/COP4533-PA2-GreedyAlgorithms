#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
using namespace std;

void firstInFirstOut(int k, vector<string> requests, ofstream& outfile){
    queue<string> cache;
    int numMisses = 0;

    for(int i = 0; i < requests.size(); i++){
        // searching for item in cache
        queue<string> temp(cache);
        bool found = false;
        while(!temp.empty()){
            if(temp.front() == requests[i]){
                found = true;
            }
            temp.pop();
        }
        // if item isn't in the cache / we have a miss
        if(found == false){
            // if cache is full, remove first element in
            if(cache.size() >= k){
                cache.pop();
            }
            // insert item into the cache
            cache.push(requests[i]);
            numMisses += 1;
        }
    }

    outfile << "FIFO: " + to_string(numMisses) << endl;
}