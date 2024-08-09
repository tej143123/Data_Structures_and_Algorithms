#include<bits/stdc++.h>
using namespace std;

class Node{
public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value

public:
    // constructor
    Node(int data1, Node* next1){
        data = data1;  // initialize the data with the provided value
        next = next1;  // initialize the next with the provided
    }

public: 
    Node(int data1){
        data = data1;  // Initialize data with the provided value
        next = nullptr;  // Initialize data with the provided value
    }
};

int main(){
    vector<int>arr = {2, 3, 5, 4};
    Node* y = new Node(arr[0]);
    cout<<y->data;
}

