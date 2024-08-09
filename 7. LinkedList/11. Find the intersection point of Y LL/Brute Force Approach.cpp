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

Node* findIntersectionPointOfLL(Node* head1, Node* head2){
     // Edge Case
    if(head1 == NULL || head2 == NULL) return NULL;
    map<Node*, int> mpp;
    Node* temp = head1;
    while(temp != NULL){
        mpp[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


// TC---> O(N1 log M) + O(N2 log M) 
// SC---> O(N1)