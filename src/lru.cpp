#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Node{
    // node for doubly-linked list implementation
    public:
        int id;
        Node* next;
        Node* prev;

        Node(int id){
            this->id = id;
            next = nullptr;
            prev = nullptr;
        }
};

void leastRecentlyUsed(int k, vector<int> requests, ofstream& outfile){
	cout << "LRU..." << endl;
    // first request will be a miss, initialize head/tail
    int numMisses = 1;
    int cacheSize = 1;
    Node* head = new Node(requests[0]);
    Node* tail = head;
    for(int i = 1; i < requests.size(); i++){
        // searching for item in cache
        Node* curNode = head;
        bool found = false;
        while(curNode != nullptr) {
            if(curNode->id == requests[i]) {
                found = true;
                // move node to the head of double linked list. head = most recently used
                // remove node from current position
                if(curNode->prev != nullptr){
                    curNode->prev->next = curNode->next;
                	if(curNode->next != nullptr) {
                    	curNode->next->prev = curNode->prev;
                	} else{
						tail = curNode->prev;
					}

                	head->prev = curNode;
                	curNode->next = head;
                	curNode->prev = nullptr;
                	head = curNode;
                	break;
				}
            }
            curNode = curNode->next;
        }

        if(!found){
            // if cache is full, remove tail (least recently used)
            if(cacheSize >= k){
                Node* newTail = tail->prev;
				if(newTail != nullptr){
					newTail->next = nullptr;
				}
                delete tail;
                tail = newTail;
				cacheSize--;
            }
            // insert new node
            cacheSize++;
            Node* newHead = new Node(requests[i]);
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
            numMisses++;
        }
    }

    outfile << "LRU: " << numMisses << endl;
}