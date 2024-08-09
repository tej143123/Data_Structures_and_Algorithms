#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    } 

public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i], nullptr, mover);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* deleteOccurences(Node* head, int key){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->back;
            if(nextNode) nextNode->back = prevNode;
            if(prevNode) prevNode->next = nextNode;
            free(temp);
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }
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
    vector<int>arr = {10, 20, 10, 10, 50};
    Node* head = convertArr2DLL(arr);
    head = deleteOccurences(head, 10);
    print(head);
    return 0;
}

// TC---> O(N)
// SC---> O(1)