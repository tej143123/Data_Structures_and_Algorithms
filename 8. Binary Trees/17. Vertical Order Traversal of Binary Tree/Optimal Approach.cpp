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

vector<vector<int>> verticalTraversal(Node* root){
    map<int, map<int, multiset<int>>> mpp;
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        root = p.first;
        int vertical = p.second.first;
        int level = p.second.second;
        mpp[vertical][level].insert(root->data);
        if(root->left){
            q.push({root->left, {vertical - 1, level + 1}});
        }
        if(root->right){
            q.push({root->right, {vertical + 1, level + 1}});
        }
    }

    vector<vector<int>>ans;
    for(auto it: mpp){
        vector<int>level;
        for(auto ele : it.second){
            level.insert(level.end(), ele.second.begin(), ele.second.end());
        }
        ans.push_back(level);
    }

    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<vector<int>>ans = verticalTraversal(root);
    cout<<" The Vertical Traversal Of Binary Tree is : ";
    for(auto it: ans){
        for(auto ele: it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// TC---> O(N log N) 
// SC---> O(N) + O(N)