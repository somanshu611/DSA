// problem link : https://leetcode.com/problems/binary-tree-preorder-traversal/

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

// Since Stack works on LIFO, we will have to insert first right and then left node
// into the stack.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        vector<int> ans;
        while(!st.empty()) {
            TreeNode* node = st.top();
            if(node==NULL) return ans;
            st.pop();
            ans.push_back(node->val);
            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
        }
        return ans;
    }
};

// Time complexity : O(n)
// Space Complexity : O(n) , in worst case, only data and right for each node, no left node.
// or O(h) in general, where h is the height of the tree