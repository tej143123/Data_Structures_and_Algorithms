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

Node* collisionPoint(Node* temp1, Node* temp2, int d){
    while(d){
        d--;
        temp2 = temp2->next;
    }
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}

Node* findIntersectionPointOfLL(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == NULL) temp1 = head2;
        if(temp2 == NULL) temp2 = head1;
    }
    return temp1;
}


// TC---> O(N1 + N2)
// SC---> O(1)