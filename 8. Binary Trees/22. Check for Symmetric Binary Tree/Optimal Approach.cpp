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

bool check(Node* left, Node* right){
    if(left == NULL || right == NULL){
        return left == right;
    }
    if(left->data != right->data) return false;

    bool check1 = check(left->left, right->right);
    bool check2 = check(left->right, right->left);

    return check1 && check2; 
}

bool isSymmetric(Node* root){
    if(root == NULL) return true;

    return check(root->left, root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    bool ans = isSymmetric(root);
    if(ans){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    
    return 0;
}

// TC---> O(N)
// SC---> O(N)  