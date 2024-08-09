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

bool check(Node* root, int minVal, int maxVal){
    if(root == NULL) return true;
    if(root->data >= maxVal || root->data <= minVal) return false;
    return check(root->left, minVal, root->data) && check(root->right, root->data, maxVal);
}

bool isValidBST(Node* root){
    return check(root, INT_MIN, INT_MAX);
}


int main(){
    Node* root = new Node(13);
    root->left = new Node(10);
    root->right = new Node(15);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->left->left->right = new Node(9);
    root->left->left->right->left = new Node(8);
    root->right->left = new Node(14);
    root->right->right = new Node(17);
    root->right->right->left = new Node(16);

    bool ans = isValidBST(root);
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