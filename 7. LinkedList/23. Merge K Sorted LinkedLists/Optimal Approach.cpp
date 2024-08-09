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


Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<pair<int, Node*>, 
    vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    for(int i=0;i<listArray.size();i++){
        if(listArray[i]){
            pq.push({listArray[i]->data, listArray[i]});
        }
    }
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.second->next){
            pq.push({it.second->next->data, it.second->next});
        }
        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
}


// TC---> O(K log K) + O(N * K *3 log K)
// SC---> O(K)
