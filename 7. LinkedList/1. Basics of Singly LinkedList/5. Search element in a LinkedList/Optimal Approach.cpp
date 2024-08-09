#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        this->data = data1;
        this->next = next1;
    }
    
public:
    Node(int data1){
        this->data = data1;
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

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int>arr = {2, 1, 5, 8};
    Node* head = convertArr2LL(arr);
    cout<<checkIfPresent(head, 8);
}

// TC---> O(N)
// SC---> O(1)