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

    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

Node* addOne(Node* head){
    // Edge Case
    if(head == NULL){
        head = new Node(1);
        return head;
    }

    // Step 1 : Reverse the given LinkedList
    Node* newHead = reverseLL(head);

    // Step 2 : perform the operation
    Node* temp = newHead;
    int carry = 1;
    while(temp != NULL){
        int sum = carry;
        sum += temp->data;
        temp->data = sum % 10;
        carry = sum / 10;
        temp = temp->next;
        if(carry == 0){
            break;
        }
    }
    
    // Step 3 : Reverse the LinkedList & Create a new Node if still carry exists
    if(carry){
        newHead = reverseLL(newHead);
        Node* newNode = new Node(1);
        newNode->next = newHead;
        return newNode;
    }
    newHead = reverseLL(newHead);
    return newHead;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int>arr = {1, 5, 9};
    Node* head = convertArr2LL(arr);
    head = addOne(head);
    print(head);
    return 0;
}

// TC---> O(N) + O(N) + O(N) ---> O(3N)
// SC---> O(1) 