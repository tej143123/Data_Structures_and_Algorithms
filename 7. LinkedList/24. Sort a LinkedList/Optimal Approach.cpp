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

Node* findMiddleElementOfLL(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
        else{
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
    if(temp1){
        temp->next = temp1;
    }
    else{
        temp->next = temp2;
    }
    Node* newHead = dummyNode->next;
    return newHead;
}

Node* sortLL(Node* head){
    // Base Case
    if(head == NULL || head->next == NULL) return head;
    Node* middle = findMiddleElementOfLL(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = NULL;
    leftHead = sortLL(leftHead);
    rightHead = sortLL(rightHead);
    return mergeTwoSortedLinkedLists(leftHead, rightHead);
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

// TC---> O( log N (N+ N/2))
// SC---> O(log N) ---> Recursive Stack Space