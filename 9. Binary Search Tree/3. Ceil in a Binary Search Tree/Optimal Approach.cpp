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

int findCeilInBST(Node* root, int key){
   int ceil = -1;
   if(root == NULL) return ceil;

   while(root != NULL){
    if(root->data == key){
        ceil = root->data;
        return ceil;
    }
    else if(root->data > key){
        ceil = root->data;
        root = root->left;
    }
    else{
        root = root->right;
    }
   }

   return ceil;
}


int main(){
   Node* root = new Node(5);
   root->left = new Node(3);
   root->right = new Node(8);
   root->left->left = new Node(2);
   root->left->right = new Node(4);
   root->right->left = new Node(6);
   root->right->right = new Node(10);

   int ans = findCeilInBST(root, 7);
   cout<<"The Min value is : "<<ans<<endl;
   
   return 0;
}
// TC---> O(log N)
// SC---> O(1)