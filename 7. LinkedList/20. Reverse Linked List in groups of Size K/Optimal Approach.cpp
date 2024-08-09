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

Node*findKthNode(Node* head, int k){
    Node* temp = head;
    while(temp != NULL){
        k--;
        if(k == 0) break;
        temp = temp->next;
    }
    return temp;
}

Node* kReverse(Node* head, int k){
    Node* temp = head;
    Node* prevNode = NULL;
    while(temp != NULL){
        Node* kthNode = findKthNode(temp, k);
        if(kthNode == NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }
        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);

        if(temp == head){
            head = kthNode;
        }
        else{
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
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
    vector<int>arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = convertArr2LL(arr);
    head = kReverse(head, 3);
    print(head);
    return 0;
}

// TC---> O(N) + O(N) ---> O(2N)
// SC---> O(1)