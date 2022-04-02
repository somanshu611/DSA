// problem link : https://leetcode.com/problems/binary-tree-postorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
// -------------------- COPY PASTE FROM BELOW --------------

// Post order = L R D (Left node, right node, data of the current node)

// Approach : First we insert root node into a stack. For each node on the top, we check if it has a left node or not. 
// If it does, then we push the left node into the stack, and MAKE THE LEFT NODE REFERENCE OF THE PREVIOUS NODE TO NULL.So that
// it acts like a check, telling whether the left node is visited or not. We keep doing this until we find a node whose left node reference is NULL(either no left node present or it's been visited once).
// If it is, then we check for it's right node reference, and do that same like we do for left node reference. 

// After all this process, a time will come where the node on the top of the stack will have no left or right refernce
// in that case we will print(here pushing into ans vector) the value in the node and remove it from stack. 


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans={};
        if(root==NULL) return ans;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            if(node->left!=NULL) {
                st.push(node->left);
                node->left = NULL;
            } else if(node->right!=NULL) {
                st.push(node->right);
                node->right = NULL;
            } else {
                ans.push_back(node->val);
                st.pop();
            }
        }
        return ans;
    }
};