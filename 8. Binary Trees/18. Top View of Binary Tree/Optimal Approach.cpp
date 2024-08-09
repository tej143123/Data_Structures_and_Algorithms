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

vector<int> findTopViewOfBT(Node* root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }

    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        root = p.first;
        int vertical = p.second;
        if(mpp.find(vertical) == mpp.end()){
            mpp[vertical] = root->data;
        }
        if(root->left){
            q.push({root->left, vertical - 1});
        }
        if(root->right){
            q.push({root->right, vertical + 1});
        }
    }

    for(auto it : mpp){
        ans.push_back(it.second);
    }

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

    vector<int> ans = findTopViewOfBT(root);
    cout<<" The Top View Of Binary Tree is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)