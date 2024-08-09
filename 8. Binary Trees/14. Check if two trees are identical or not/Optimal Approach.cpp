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

bool checkIdentical(Node* root1, Node* root2){
    if(root1 == NULL || root2 == NULL){
        return (root1 == root2);
    }

    return (root1->data == root2->data)
           && checkIdentical(root1->left, root2->left)
           && checkIdentical(root1->right, root2->right);
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left = new Node(4);
    root1->right->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->right->left = new Node(4);
    root2->right->right = new Node(5);

    bool ans = checkIdentical(root1, root2);
    if(ans){
        cout<<" The Binary Trees are Identical";
    }
    else{
        cout<<" The Binary Trees are not Identical";
    }
    return 0;
}

// TC---> O(N + M)
// SC---> O(N)
