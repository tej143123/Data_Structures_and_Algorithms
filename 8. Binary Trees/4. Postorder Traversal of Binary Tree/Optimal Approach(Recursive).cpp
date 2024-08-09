#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void findPostorder(Node* root, vector<int>& arr){
    if(root == NULL) return;

    findPostorder(root->left, arr);
    findPostorder(root->right, arr);
    arr.push_back(root->data);
}

vector<int> postOrder(Node* root){
    vector<int>arr;
    findPostorder(root, arr);

    return arr;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int>ans = postOrder(root);
    cout<<" The Inoder Traversal is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)