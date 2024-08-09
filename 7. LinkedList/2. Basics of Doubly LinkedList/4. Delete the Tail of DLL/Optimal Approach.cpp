#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data;
    Node* next;
    Node* back;

public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteTailOfDLL(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* prev = NULL;
    Node* temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int>arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2DLL(arr);
    head = deleteTailOfDLL(head);
    print(head);
    return 0;
}

// TC---> O(N)
// SC---> O(1)