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

Node* reverseLL(Node* head){
    // Edge Case
    if(head == NULL || head->next == NULL) return head;

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    Node* newHead = prev;
    return newHead;
}

Node* sortLL(Node* head){
    Node* temp = head;
    vector<int>arr;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    temp = head;
    int i = 0;
    while(temp != NULL){
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int>arr = {3, 4, 2, 1, 5};
    Node* head = convertArr2LL(arr);
    head = sortLL(head);
    print(head);
    return 0;
}

// TC---> O(N) + O(N log N) + O(N)
// SC---> O(N)