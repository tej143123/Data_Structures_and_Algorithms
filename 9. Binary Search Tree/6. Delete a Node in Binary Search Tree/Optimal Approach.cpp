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

Node* findLastRight(Node* root){
    if(root->right == NULL){
        return root;
    }
    return findLastRight(root->right);
}

Node* helper(Node* root){
    if(root->left == NULL){
        return root->right;
    }
    else if(root->right == NULL){
        return root->left;
    }

    Node* leftChild = root->left;
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(leftChild);
    lastRight->right = rightChild;

    return root->left;
}

Node* deleteNodeInBST(Node* root, int key){
    // Edge Case
    if(root == NULL) return root;

    Node* temp = root;
    while(root != NULL){
        if(root->data > key){
            if(root->left != NULL && root->left->data == key){
                root->left = helper(root->left);
                break;
            }
            else{
                root = root->left;
            }
        }
        else{
            if(root->right != NULL && root->right->data == key){
                root->right = helper(root->right);
                break;
            }
            else{
                root = root->right;
            }
        }
    }

    return temp;
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
    root->left->right->right = new Node(8);

    root = deleteNodeInBST(root, 5);
    cout<<" The Binary Search Tree after deletion of node is : ";
    printInOrder(root);

    return 0;
}

// TC---> O(log N)
// SC---> O(1)