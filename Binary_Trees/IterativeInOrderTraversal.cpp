// Problem link : https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// In order -> L D R (left node, data , right node)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            if(node->left==NULL) {
                ans.push_back(node->val);
                st.pop();
                if(node->right!=NULL) st.push(node->right);
            } else {
                st.push(node->left);
                node->left = NULL;
            }
        }
        return ans;
    }
};

// In worst case of skewed tree with only left nodes, and single branch, our 
// space complexity = O(n)

// In general, space complexity = O(h), h = height of the tree.

// Time complexity = O(n)