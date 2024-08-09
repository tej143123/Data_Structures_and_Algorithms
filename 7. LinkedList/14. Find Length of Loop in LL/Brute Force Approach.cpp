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

int findLoopLengthOfLL(Node* head){
    // Edge Case
    if(head == NULL) return 0;

    int cnt = 0;
    Node* temp = head;
    map<Node*, int>mpp;
    
    while(temp != NULL){
        cnt++;
        if(mpp.find(temp) != mpp.end()){
            int val = mpp[temp];
            cnt = cnt - val;
            return cnt;
        }
        mpp[temp] = cnt;
        temp = temp->next;
    }

    return 0;
}


// TC---> O(N * 2* log N)
// SC---> O(N) 