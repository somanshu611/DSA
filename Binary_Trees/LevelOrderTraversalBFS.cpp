// Problem link : https://leetcode.com/problems/binary-tree-level-order-traversal/

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

// My initial submission
// I could've used the size of queue as a check for inserting nodes of a level in ans vector.
// Like in striver's code.Scroll down for striver's code.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        vector<int> ans2;
        int next = 0;
        int temp = 1;
        while(!q.empty()) {
            if(q.front()==NULL) return ans;
            if(q.front()->left != NULL) {
                next++;
                q.push(q.front()->left);
            }
            if(q.front()->right != NULL) {
                next++;
                q.push(q.front()->right);
            }
            temp--;
            ans2.push_back(q.front()->val);
            if(temp==0) {
                ans.push_back(ans2);
                temp = next;
                next = 0;
                ans2 = {};
            }
            q.pop();
        }
        if(ans2.size()>0) ans.push_back(ans2);
        return ans;
    }
};

// Striver's approach : 
// Pay atttention to variable naming and effective use of queue.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root == NULL) return ans; 
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            int size = q.size();
            vector<int> level; 
            for(int i = 0;i<size;i++) {
                TreeNode *node = q.front(); 
                q.pop(); 
                if(node->left != NULL) q.push(node->left); 
                if(node->right != NULL) q.push(node->right); 
                level.push_back(node->val); 
            }
            ans.push_back(level); 
        }
        return ans; 
    }
};