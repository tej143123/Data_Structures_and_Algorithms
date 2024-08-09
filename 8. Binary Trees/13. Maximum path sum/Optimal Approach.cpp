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

int findMax(Node* root, int& maxi){ 
    if(root == NULL) return 0;

    int leftSum = findMax(root->left, maxi);
    int rightSum = findMax(root->right, maxi);

    maxi = max(maxi, root->data + leftSum + rightSum);

    return root->data + max(leftSum, rightSum);
}

int findMaximumPathSum(Node* root){
    int maxi = 0;
    findMax(root, maxi);
    return maxi;
}

int main(){
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    
    int ans = findMaximumPathSum(root);
    cout<<ans<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)
