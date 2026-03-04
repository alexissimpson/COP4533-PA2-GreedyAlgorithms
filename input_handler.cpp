#include "input_handler.h"
#include "fifo.h"
#include "lru.h"
#include "optff.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void handleInput(string filename){
    ofstream outfile("../data/output/OUTPUT.txt");
    ifstream infile("../data/input/" + filename);
    string line;

    // store k (cache capacity) and m (number of requests) from first line
    if(!getline(infile, line)){
        outfile << "File is empty! Terminating..." << endl;
        return;
    }
    stringstream ss(line);
    string k;
    getline(ss, k, ' ');
    int k = stoi(k);
    string m;
    getline(ss, m, ' ');
    int m = stoi(m);

    // storing requests
    if(!getline(infile, line)){
        outfile << "Error: No requests." << endl;
        return;
    }
    stringstream ss2(line);
    vector<int> requests;
    string request;
    while(getline(ss2, request, ' ')){
        requests.push_back(stoi(request));
    }

    infile.close();

    // calling cache eviction functions
    firstInFirstOut(k, requests, outfile);
    leastRecentlyUsed(k, requests, outfile);
    farthestInTheFuture(k, requests, outfile);

    outfile.close();
}

