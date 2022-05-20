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

// First search for the node.
// then Search for extremem right of the left node, and make
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = root;
        while(node) {
            if(node->val==key) { // special code for deleting the root of the tree
                if(node->left==NULL) return node->right;
                if(node->right==NULL) return node->left;
                TreeNode* temp = fun(node->left);
                temp->right = node->right;
                root = node->left;
                return root;
            }
            if(key<node->val) {
                if((node->left!=NULL) && (node->left->val==key)) {
                    node->left = del(node->left);
                    return root;
                } else node = node->left;
            } else {
                if((node->right!=NULL) && (node->right->val==key)) {
                    node->right = del(node->right);
                    return root;
                } else node = node->right;
            }
        }
        return root;
    }
    TreeNode* del(TreeNode* node) {
        if(node->left==NULL) {
            return node->right;
        } else if(node->right==NULL) {
            return node->left;
        } else {
            TreeNode* temp = fun(node->left);
            temp->right=node->right;
            return node->left;
        }
    }
    TreeNode* fun(TreeNode* node) { // returns reference to extreme right node of the left sub tree.
        while(node->right!=NULL) node = node->right;
        return node;
    }
};