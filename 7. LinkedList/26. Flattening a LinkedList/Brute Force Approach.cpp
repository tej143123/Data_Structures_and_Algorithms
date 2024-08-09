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

Node* convertArr2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->child = newNode;
        temp = newNode;
    }
    return head;
}

Node* flattenLL(Node* head){
    Node* temp = head;
    vector<int>arr;
    while(temp != NULL){
        Node* t2 = temp;
        while(t2 != NULL){
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    head = convertArr2LL(arr);
    return head;
}



// TC---> O(N * M) + O(X log X) + O(N * M) ---> X = (N * M)
// SC---> O(N * M) * 2