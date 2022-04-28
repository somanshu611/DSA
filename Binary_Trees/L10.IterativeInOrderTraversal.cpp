// Problem link : https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// In order -> L D R (left node, data , right node)
// In our recursive approach, auxillary stack space will be used. We can use that same stack
// but created by us, and do it iteratively.
// In worst case of skewed tree with only left nodes and single branch, our 
// space complexity = O(n)

// In general, space complexity = O(h), h = height of the tree.

// Time complexity = O(n)

// Approach 1 : My initial approach but this one alters the given tree itself, thus this isn't 
// a feasible approach.

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


// Approach 2 : Intended approach, no altering of the original tree.
// We need previous history of all the nodes when we are going deep into the left of the tree, for
// that we need stack and a node through which we'll be traversing. 

// In my previous approach, i made the node->left = NULL whenever i traveresed the left subtree of a node
// and this served as a check so that i don't traverse
// the left subtree of the node again. In this approach, we are keeping a node which basically 
// does the same thing. If node==NULL, then that means left subtree has been traversed. 
//Now, it's time for right sub-tree.

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true) {
            if(node!=NULL) {
                st.push(node);
                node = node->left;
            }
            else {
                if(st.empty()) break;
                ans.push_back(st.top()->val);
                node = st.top()->right;
                st.pop();
            }
        }
        return ans;
    }
};