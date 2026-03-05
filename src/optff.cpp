#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

map<string, queue<int>> handleInput(vector<string>& requests){
    map<string, queue<int>> requestIndices; // map [request, queue of indices]
    for(int i=0; i<requests.size(); i++) {
        requestIndices[requests[i]].push(i);
    }
}
