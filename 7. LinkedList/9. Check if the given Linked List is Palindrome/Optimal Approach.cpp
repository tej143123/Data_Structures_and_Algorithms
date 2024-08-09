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
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool checkPalindrome(Node* head){
    // Edge Cases
    if(head == NULL || head->next == NULL) return true;
    
    // step 1 : Finding the first middle element
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // step 2 : Reverse the second half of LinkedList
    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != NULL){
        if(first->data != second->data){
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}

int main(){
    vector<int>arr = {1, 2, 3, 2, 1};
    Node* head = convertArr2LL(arr);
    if(checkPalindrome(head)){
        cout<<" True ";
    }
    else{
        cout<<" False ";
    }
    return 0;
}

// TC---> O(2N)
// SC---> O(1) 