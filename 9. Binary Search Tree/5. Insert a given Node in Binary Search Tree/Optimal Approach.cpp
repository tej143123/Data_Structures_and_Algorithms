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

Node* insertNodeInBST(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    Node* temp = root;
    while(temp != NULL){
        if(temp->data <= val){
            if(temp->right != NULL){
                temp = temp->right;
            }
            else{
                temp->right = new Node(val);
                break;
            }
        }
        else{
            if(temp->left != NULL){
                temp = temp->left;
            }
            else{
                temp->left = new Node(val);
                break;
            }
        }
    }
    return root;
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
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    root = insertNodeInBST(root, 5);
    cout<<" The BST after insertion node is : ";
    printInOrder(root);

    return 0;
}

// TC---> O(log N)
// SC---> O(1)