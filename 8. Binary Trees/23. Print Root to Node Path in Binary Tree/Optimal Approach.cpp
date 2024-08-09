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

bool getPath(Node* root, vector<int>& ans, int X){
    if(root == NULL){
        return false;
    }

    ans.push_back(root->data);
    if(root->data == X) return true;
    bool left = getPath(root->left, ans, X);
    bool right = getPath(root->right, ans, X);
    if(left || right) return true;

    ans.pop_back();

    return false;
}

vector<int> findRootToNodePath(Node* root, int X){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    getPath(root, ans, X);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> ans = findRootToNodePath(root, 7);
    cout<<" The Root to Node Path is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)  