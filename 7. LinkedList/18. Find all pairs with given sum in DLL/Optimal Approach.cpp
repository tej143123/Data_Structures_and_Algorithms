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

vector<pair<int, int>> findPairs(Node* head, int sum){
    vector<pair<int, int>> pairs;
    Node* temp1 = head;
    while(temp1 != NULL){
        Node* temp2 = temp1->next;
        while(temp2 != NULL && (temp1->data + temp2->data) <= sum){
            if((temp1->data + temp2->data) == sum){
                pairs.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return pairs;
}


// TC---> O(N) + O(N)
// SC---> O(1)