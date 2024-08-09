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

int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while (temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main(){
    vector<int>arr = {2, 1, 3, 8};
    Node* head = convertArr2LL(arr);
    cout<<lengthOfLL(head); 
}

// TC---> O(N)
// SC---> O(1)