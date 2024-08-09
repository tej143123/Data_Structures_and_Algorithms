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

Node* convertArr2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}


Node* mergeKLists(vector<Node*> &listArray){
    vector<int>arr;
    for(int i=0;i<listArray.size();i++){
        Node* temp = listArray[i];
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }
    sort(arr.begin(), arr.end());
    Node* head = convertArr2LL(arr);
    return head;
}


// TC---> O(M) + O(M log M) + O(M) ---> M ---> N * K
// SC---> O(M) + O(M)
Node* mergeTwoSortedLists(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            temp->next = temp1;
            temp = temp1;
            temp1 = temp1->next;
        }
    }
}