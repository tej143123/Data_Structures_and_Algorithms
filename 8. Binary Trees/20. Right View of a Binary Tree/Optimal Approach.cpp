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

void findRightView(Node* root, int level, vector<int>& ans){
    if(root == NULL){
        return;
    }
    
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    findRightView(root->right, level + 1, ans);
    findRightView(root->left, level + 1, ans);
}

vector<int> findRightViewOfBT(Node* root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }

    findRightView(root, 0, ans);
    
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = findRightViewOfBT(root);
    cout<<" The Right View of Binary Tree is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    
    return 0;
}

// TC---> O(N)
// SC---> O(N)  