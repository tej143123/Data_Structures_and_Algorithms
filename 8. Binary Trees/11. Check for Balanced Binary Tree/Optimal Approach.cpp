#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int findHeight(Node* root){
    if(root == NULL) return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    if(leftHeight == -1 || rightHeight == -1) return -1;
    if(abs(leftHeight - rightHeight) > 1) return -1;
    return 1 + max(leftHeight, rightHeight);
}

bool checkBalancedBinaryTree(Node* root){
    return findHeight(root) != -1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->left->right = new Node(4);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(6);

    bool ans = checkBalancedBinaryTree(root);
    if(ans){
        cout<<" True";
    }
    else{
        cout<<" False";
    }

    return 0;
}

// TC---> O(N)
// SC---> O(N)
