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
    Node* temp1 = head1;
    Node* temp2 = head2;
    int N1 = 0, N2 = 0;
    while(temp1 != NULL){
        N1++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        N2++;
        temp2 = temp2->next;
    }
    if(N1 < N2){
        return collisionPoint(head1, head2, N2 - N1);
    }
    else{
        return collisionPoint(head2, head1, N1 - N2);
    }
    return NULL;
}


// TC---> O(N1) + O(N2) + O(difference(N1, N2)) + O(MIN(N1, N2))
// SC---> O(1)