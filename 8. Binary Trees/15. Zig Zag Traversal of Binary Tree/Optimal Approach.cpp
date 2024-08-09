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

vector<vector<int>> zigzagTraversal(Node* root){
    vector<vector<int>>ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    bool LeftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            root = q.front();
            q.pop();
            int index = (LeftToRight) ? i : (size - 1 -i);
            level[index] = root->data;

            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
        }

        LeftToRight = !LeftToRight;
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
    root->right->right = new Node(6);

    vector<vector<int>>ans = zigzagTraversal(root);
    cout<<" The zig-zag traversal is : ";
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