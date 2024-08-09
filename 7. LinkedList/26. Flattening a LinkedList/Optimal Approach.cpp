#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data; 
    Node* next; 
    Node* child;

public:
    // constructor
    Node(int data1, Node* next1, Node* child1){
        data = data1;  
        next = next1;  
        child = child1;
    }

public: 
    Node(int data1){
        data = data1;  
        next = nullptr; 
        child = nullptr; 
    }
};

Node* mergeTwoLists(Node* head1, Node* head2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            res->child = head1;
            res = head1;
            head1 = head1->child;
        }
        else{
            res->child = head2;
            res = head2;
            head2 = head2->child;
        }
        res->next = NULL;
    }
    if(head1){
        res->child = head1;
    }
    else{
        res->child = head2;
    }
    return dummyNode->child;
}

Node* flattenLL(Node* head){
    // Base Case
    if(head == NULL || head->next == NULL) return head;
    Node* mergedNode = flattenLL(head->next);
    return mergeTwoLists(head, mergedNode);
}



// TC---> O(N * 2M) ---> M is Vertical Length & N is Horizontal Length
// SC---> O(N) ---> Recursive Stack Space