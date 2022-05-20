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
    bool validate(TreeNode* root,long long l,long long r) {
        if((root->val<r) && (root->val>l)) {
            return (root->left!=NULL ? validate(root->left,l,root->val) : true) && 
                    (root->right!=NULL ? validate(root->right,root->val,r) : true);
        } else return false;
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,LLONG_MIN,LLONG_MAX);
    }
};