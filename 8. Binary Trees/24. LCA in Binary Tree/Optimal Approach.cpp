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

Node* findLowestCommonAncestor(Node* root, Node* p, Node* q){
    // Base Case
    if(root == NULL || root == p || root == q){
        return root;
    }

    Node* left = findLowestCommonAncestor(root->left, p, q);
    Node* right = findLowestCommonAncestor(root->right, p, q);

    if(left == NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    else{
        return root;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(9);

    Node* p = root->left->left;
    Node* q = root->left->right->right;
    root = findLowestCommonAncestor(root, p, q);
    cout<<" The Lowest Common Ancestor is :"<< root->data<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)  