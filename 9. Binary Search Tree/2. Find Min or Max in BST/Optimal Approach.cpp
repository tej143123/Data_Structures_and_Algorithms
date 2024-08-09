#include<bits/stdc++.h>
using namespace std;

class Node{
public:
   int data;
   Node* left;
   Node* right;

   Node(int val){
    data = val;
    left = nullptr;
    right = nullptr;
   }
};

int findMinInBST(Node* root){
   if(root == NULL) return -1;
   while(root->left != NULL){
    root = root->left;
   }

   return root->data;
}


int main(){
   Node* root = new Node(5);
   root->left = new Node(3);
   root->right = new Node(8);
   root->left->left = new Node(2);
   root->left->right = new Node(4);
   root->right->left = new Node(6);
   root->right->right = new Node(10);

   int ans = findMinInBST(root);
   cout<<"The Min value is : "<<ans<<endl;
   
   return 0;
}
// TC---> O(log N)
// SC---> O(1)