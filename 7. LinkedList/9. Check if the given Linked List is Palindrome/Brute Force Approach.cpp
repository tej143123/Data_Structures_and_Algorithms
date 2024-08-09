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

bool checkPalindrome(Node* head){
    // Edge Cases
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node* temp = head;
    stack<int>st;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }
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
// SC---> O(N) 