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

int findLength(Node* slow, Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow != fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int findLengthOfLoopOfLL(Node* head){
   Node* slow = head;
   Node* fast = head; 

   while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next;
    if(slow == fast) return findLength(slow, fast);
   }
   return 0;
}


// TC---> O(N)
// SC---> O(1) 