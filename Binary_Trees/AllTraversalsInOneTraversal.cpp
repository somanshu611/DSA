// There' no link for this one

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

class Solution {
public:
    vector<int> PreInPostTraversals(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        vector<int> pre,in,post;
        st.push({root,1});
        while(!st.empty()) {
            auto it = st.top();
            st.pop();
            TreeNode* node = it.first;
            int num = it.second;

            // pre
            // increment 1 to 2
            // push the left node to stack
            if(num==1) {
                pre.push_back(node->val);
                st.push({node,2});
                if(node->left!=NULL) st.push({node->left,1});
            } 
            // in
            // increment 2 to 3
            // push the right node to stack
            else if(num==2) {
                in.push_back(node->val);
                st.push({node,3});
                if(node->right!=NULL) st.push({node->right,1});
            } 
            // post
            // don't push anything now
            else {
                post.push_back(node->val);
            }
        }
    }
};