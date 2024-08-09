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

void inOrder(Node* root, vector<int>& ans){
    if(root == NULL) return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

int findKthSmallestElementInBST(Node* root, int k){
    vector<int>ans; 
    inOrder(root, ans);
    
    return ans[k - 1];
}

void printInOrder(Node* root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(3);
    root->left->left->right = new Node(4);
    root->left->right->left = new Node(6);

    int ans = findKthSmallestElementInBST(root, 3);
    printInOrder(root);
    cout<<endl;
    cout<<" The Kth Smallest Element in Binary Search Tree is : "<<ans<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)