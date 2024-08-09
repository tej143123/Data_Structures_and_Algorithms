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

int findMax(Node* root, int& diameter){ 
    if(root == NULL) return 0;

    int leftHeight = findMax(root->left, diameter);
    int rightHeight = findMax(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int findDiameter(Node* root){
    int diameter = 0;
    findMax(root, diameter);
    return diameter;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(7);
    root->right->left->left = new Node(5);
    root->right->left->left->left = new Node(6);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);

    int ans = findDiameter(root);
    cout<<ans<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)
