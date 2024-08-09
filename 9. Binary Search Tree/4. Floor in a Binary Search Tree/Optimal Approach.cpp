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

int findFloorInBST(Node* root, int key){
   int floor = -1;
   if(root == NULL) return floor;

   while(root != NULL){
    if(root->data == key){
        floor = root->data;
        return floor;
    }
    else if(root->data < key){
        floor = root->data;
        root = root->right;
    }
    else{
        root = root->left;
    }
  }

  return floor;
}


int main(){
   Node* root = new Node(5);
   root->left = new Node(3);
   root->right = new Node(8);
   root->left->left = new Node(2);
   root->left->right = new Node(4);
   root->right->left = new Node(6);
   root->right->right = new Node(10);

   int ans = findFloorInBST(root, 7);
   cout<<"The Min value is : "<<ans<<endl;
   
   return 0;
}
// TC---> O(log N)
// SC---> O(1)