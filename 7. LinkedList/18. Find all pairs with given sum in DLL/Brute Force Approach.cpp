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

// TC---> O(N^2)
// SC---> O(1)