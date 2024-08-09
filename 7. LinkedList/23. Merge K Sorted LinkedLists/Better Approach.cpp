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


Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data <= temp2->data){
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
        else{
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
    }

    if(temp1 != NULL){
        temp->next = temp1;
    }
    else{
        temp->next = temp2;
    }
    Node* head = dummyNode->next;
    return head;
}

Node* mergeKLists(vector<Node*> &listArray){
    Node* head = listArray[0];
    for(int i=1;i<listArray.size();i++){
        head = mergeTwoSortedLinkedLists(head, listArray[i]);
    }
    return head;
}


// TC---> O(N*(K*(K+1)/2))
// SC---> O(1)
