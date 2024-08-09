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

vector<vector<int>> levelOrderTraversal(Node* root){
    vector<vector<int>>ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>>ans = levelOrderTraversal(root);
    cout<<" The level order traversal is : ";
    for(auto it: ans){
        cout<<"[ ";
        for(auto val: it){
            cout<<val<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
    return 0;
}

// TC---> O(N)
// SC---> O(N)