#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data;
    Node* next;

public:
    Node(int data1, Node* next1){
        this->data = data1;
        this->next = next1;
    }

public:
    Node(int data1){
        this->data = data1;
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

Node* deleteKthElementOfLL(Node* head, int k){
    if(head == NULL) return NULL;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    vector<int>arr = {1, 8, 9, 3};
    Node* head = convertArr2LL(arr);
    int k = 5;
    head = deleteKthElementOfLL(head, k);
    print(head);
}

// TC---> O(N)
// SC---> O(1)