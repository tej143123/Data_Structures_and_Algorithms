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

void findPreorder(Node* root, vector<int>& arr){
    if(root == NULL) return;

    arr.push_back(root->data);
    findPreorder(root->left, arr);
    findPreorder(root->right, arr);
}

vector<int> preorder(Node* root){
    vector<int>arr;
    findPreorder(root, arr);
    return arr;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int>ans = preorder(root);
    cout<<" The Preorder Traversal is : ";
    for(auto val: ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)