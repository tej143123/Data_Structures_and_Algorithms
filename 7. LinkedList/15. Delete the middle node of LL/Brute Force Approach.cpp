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

Node* deleteMiddleNodeOfLL(Node* head){
    // Edge Case
    if(head == NULL || head->next == NULL) return NULL;
    
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    temp = head;
    int res = cnt / 2;
    while(temp != NULL){
        res--;
        if(res == 0){
            Node* middleNode = temp->next;
            temp->next = temp->next->next;
            free(middleNode);
            break;
        }
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
    vector<int>arr = {1, 2, 3, 4, 5, 6};
    Node* head = convertArr2LL(arr);
    head = deleteMiddleNodeOfLL(head);
    print(head);
    return 0;
}

// TC---> O(N) + O(N/2)
// SC---> O(1)