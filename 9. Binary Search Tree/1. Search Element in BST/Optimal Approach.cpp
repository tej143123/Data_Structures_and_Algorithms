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

Node* searchInBST(Node* root, int val){
   while(root != NULL && root->data != val){
      root = val < root->data ? root->left : root->right;
   }

   return root;
}


int main(){
   Node* root = new Node(5);
   root->left = new Node(3);
   root->right = new Node(8);
   root->left->left = new Node(2);
   root->left->right = new Node(4);
   root->right->left = new Node(6);
   root->right->right = new Node(10);

   root = searchInBST(root, 6);
   if(root){
      cout<<" The Element is Found";
   }
   else{
      cout<<" The Element is not Found";
   }
   cout<<endl;
   return 0;
}
// TC---> O(log N)
// SC---> O(1)