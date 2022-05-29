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


// Haven't watched video editorial yet.
class Solution {
public:
    int mx = -4*1e7;
    int maxPath(TreeNode* root) {
        if((root->left==NULL) && (root->right==NULL)) {
            mx = max(mx,root->val);
            return root->val;
        }
        
        int l = (root->left==NULL) ? -4*1e7 : maxPath(root->left);
        int r = (root->right==NULL) ? -4*1e7 : maxPath(root->right);
        mx = max({l,r,root->val,l+root->val,r+root->val,l+r+root->val,mx});
        return max({l+root->val,r+root->val,root->val});     
    }
    
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return mx;
    }
};