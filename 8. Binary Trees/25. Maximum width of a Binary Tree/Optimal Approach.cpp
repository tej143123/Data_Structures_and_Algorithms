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

int findMaxWidth(Node* root){
    // Base Case
    int ans = 0;
    if(root == NULL) return 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int size = q.size();
        int minimumIndex = q.front().second;
        int first, last;
        for(int i=0;i<size;i++){
            int cur_index = q.front().second - minimumIndex;
            root = q.front().first;
            q.pop();
            if(i == 0) first = cur_index;
            if(i == size - 1) last = cur_index;
            
            if(root->left){
                q.push({root->left, 2*cur_index + 1});
            }
            if(root->right){
                q.push({root->right, 2*cur_index + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }

    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->right->right = new Node(9);

    int width = findMaxWidth(root);
    cout<<" The Maximum Width of Binary Tree is : "<<width<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)  