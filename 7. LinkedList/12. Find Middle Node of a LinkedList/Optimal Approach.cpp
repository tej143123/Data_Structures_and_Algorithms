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

Node* findMiddleNodeOfLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void print(Node* head){
    if(head != NULL){
        cout<<head->data<<endl;
    }
}

int main(){
    vector<int>arr = {1, 2, 3, 4, 5, 6};
    Node* head = convertArr2LL(arr);
    head = findMiddleNodeOfLL(head);
    print(head);
    return 0;
}

// TC---> O(N)
// SC---> O(1)