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

vector<int> inOrder(Node* root){
    vector<int>ans;
    if(root == NULL) return ans;
    
    stack<Node*>st;
    while(root != NULL || !st.empty()){
        if(root == NULL && !st.empty()){
            root = st.top();
            st.pop();
            ans.push_back(root->data);
            root = root->right;
        }
        else{
            st.push(root);
            root = root->left;
        }
    }
    return ans;
}

void treeTraversals(Node* root, vector<vector<int>>&ans){
    if(root == NULL) return;

    ans[1].push_back(root->data);
    treeTraversals(root->left, ans);
    ans[0].push_back(root->data);
    treeTraversals(root->right, ans);
    ans[2].push_back(root->data);
}
vector<vector<int>> getTreeTraversal(Node* root){
    vector<vector<int>>ans={{},{},{}};
    treeTraversals(root, ans);
    return ans;
}

// TC---> O(3N)
// SC---> O(H) ---> Height of the tree