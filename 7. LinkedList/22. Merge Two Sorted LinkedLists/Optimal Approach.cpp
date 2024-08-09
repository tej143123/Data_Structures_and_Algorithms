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


Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data <= temp2->data){
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

    if(temp1 != NULL){
        temp->next = temp1;
    }
    else{
        temp->next = temp2;
    }
    Node* head = dummyNode->next;
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int>arr1 = {2, 4, 8, 10};
    vector<int>arr2 = {1, 3, 3, 6, 11, 14};
    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2); 
    Node* head = mergeTwoSortedLinkedLists(head1, head2);
    print(head);
    return 0;
}

// TC---> O(N1 + N2)
// SC---> O(1)