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

Node* insertNodeBeforeValue(Node* head, int val, int ele){
    if(head == NULL){
        return NULL;
    }

    if(head->data == val){
        Node* temp = new Node(ele, head);
        return temp;
    }

    Node* temp2 = new Node(ele);
    Node* prev = NULL;
    Node* temp1 = head;
    while(temp1 != NULL){
        if(temp1->data == val){
            prev->next = temp2;
            temp2->next = temp1;
            break;
        }
        prev = temp1;
        temp1 = temp1->next;
    }
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
    int val = 8;
    int ele = 6;
    head = insertNodeBeforeValue(head, val, ele);
    print(head);
}

// TC---> O(N)
// SC---> O(1)