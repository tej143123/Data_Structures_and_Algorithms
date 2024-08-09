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

vector<int> postOrder(Node* root){
    vector<int>postorder;
    if(root == NULL) return postorder;

    stack<Node*>st1, st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left){
            st1.push(root->left);
        }
        if(root->right){
            st1.push(root->right);
        }
    }
    while(!st2.empty()){
        root = st2.top();
        st2.pop();
        postorder.push_back(root->data);
    }

    return postorder;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->left->right->right = new Node(8);

    vector<int> ans = postOrder(root);
    cout<<" The postOrder Traversal is : ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

// TC---> O(N)
// SC---> O(2N)