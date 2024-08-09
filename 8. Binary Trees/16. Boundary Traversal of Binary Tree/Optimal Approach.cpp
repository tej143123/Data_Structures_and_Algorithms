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

bool isLeaf(Node* root){
    return !root->left && !root->right;
}

void addLeftBoundary(Node* root, vector<int>& ans){
    Node* cur = root->left;
    while(cur){
        if(!isLeaf(cur)){
            ans.push_back(cur->data);
        }
        if(cur->left){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }
}

void addLeaves(Node* root, vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }

    if(root->left){
        addLeaves(root->left, ans);
    }
    if(root->right){
        addLeaves(root->right, ans);
    }
}

void addRightBoundary(Node* root, vector<int>& ans){
    Node* cur = root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)){
            temp.push_back(cur->data);
        }
        if(cur->right){
            cur = cur->right;
        }
        else{
            cur = cur->left;
        }
    }

    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    if(!isLeaf(root)){
        ans.push_back(root->data);
    }
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);

    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->left->right = new Node(11);

    vector<int>ans = boundaryTraversal(root);
    cout<<" The Boundary Traversal Of Binary Tree is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)