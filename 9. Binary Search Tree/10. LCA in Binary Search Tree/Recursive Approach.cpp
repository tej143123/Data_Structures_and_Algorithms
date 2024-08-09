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

Node* findLCAofBST(Node* root, int key1, int key2){
    if(root == NULL) return NULL;
    if(root->data > key1 && root->data > key2){
        return findLCAofBST(root->left, key1, key2);
    }
    else if(root->data < key1 && root->data < key2){
        return findLCAofBST(root->right, key1, key2);
    }
    return root;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->left->left->left = new Node(1);
    root->left->left->left->right = new Node(2);
    root->left->right->left = new Node(6);;
    root->left->right->right = new Node(9);
    root->left->right->left->left = new Node(5);
    root->left->right->left->right = new Node(7);
    root->right->left = new Node(11);
    root->right->right = new Node(15);

    root = findLCAofBST(root, 5, 9);
    cout<<" The LCA of BST is : "<<root->data<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)