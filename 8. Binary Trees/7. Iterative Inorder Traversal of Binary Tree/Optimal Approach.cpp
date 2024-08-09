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

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int>ans = inOrder(root);
    cout<<" The Inorder Traversal is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(N)