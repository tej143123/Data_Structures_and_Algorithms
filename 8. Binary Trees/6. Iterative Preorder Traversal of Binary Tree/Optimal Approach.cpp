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

vector<int> preOrder(Node* root){
    vector<int>ans;
    if(root == NULL) return ans;
    
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        auto node = st.top();
        st.pop();
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
        ans.push_back(node->data);
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

    vector<int>ans = preOrder(root);
    cout<<" The Preorder Traversal is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)