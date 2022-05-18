#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int data) {
    TreeNode* node = new TreeNode(data);
    if(root==NULL) {
        root=node;
        return root;
    }
    if(data<root->val) {
        if(root->left==NULL) root->left=node;
        else insertIntoBST(root->left,data);
    } else {
        if(root->right==NULL) root->right=node;
        else insertIntoBST(root->right,data);
    }
    
    return root;
}