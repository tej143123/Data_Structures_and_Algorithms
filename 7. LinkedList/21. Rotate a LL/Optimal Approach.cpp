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

Node*findKthNode(Node* head, int k){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) return temp;
        temp = temp->next;
    }
    return temp;
}

Node* rotateLL(Node* head, int k){
    // Edge Case
    if(head == NULL || k == 0) return head;

    int len = 1;
    Node* tail = head;
    while(tail->next != NULL){
        len++;
        tail = tail->next;
    }
    if((k % len) == 0) return head;

    // connect tail node to head
    tail->next = head;
    k = k % len;
    Node* newLastNode = findKthNode(head, len - k);
    head = newLastNode->next;
    newLastNode->next = NULL;
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
    Node* head = convertArr2LL(arr);
    head = rotateLL(head, 2);
    print(head);
    return 0;
}

// TC---> O(N) + O(N) ---> O(2N)
// SC---> O(1)