#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data; 
    Node* next; 

public:
    // constructor
    Node(int data1, Node* next1){
        data = data1;  
        next = next1;  
    }

public: 
    Node(int data1){
        data = data1;  
        next = nullptr;  
    }
};

bool detectLoop(Node* head){
    map<Node*, int> mpp;
    Node* temp = head;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()) return true;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}


// TC---> O(N * 2 log M)
// SC---> O(N) 