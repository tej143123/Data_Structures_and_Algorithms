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


Node* findStartingNodeOfLL(Node* head){
    // Edge Case
    if(head == NULL || head->next == NULL) return NULL;

    map<Node*, int> mpp;
    Node* temp = head;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
}


// TC---> O(N * 2* log N)
// SC---> O(N)