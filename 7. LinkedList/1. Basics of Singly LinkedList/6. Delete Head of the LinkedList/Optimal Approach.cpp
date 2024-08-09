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

Node* deleteHeadOfLL(Node* head){
    Node* temp = head;
    if(head == NULL) return head;
    head = head->next;
    free(temp);
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    vector<int>arr = {1, 8, 9, 3};
    Node* head = convertArr2LL(arr);
    head = deleteHeadOfLL(head);
    print(head);
}

// TC---> O(N)
// SC---> O(1)