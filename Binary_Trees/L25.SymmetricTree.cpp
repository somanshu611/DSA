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

// This problem looks easy but it isn't.
// THE MIRROR PROPERTY is very crucial here.
// 

class Solution {
public:
    bool check(TreeNode* r1,TreeNode* r2) {
        if((r1!=NULL) && (r2!=NULL)) {
            if((r1->val)==(r2->val)) {
                return (check(r1->left,r2->right)) && (check(r1->right,r2->left));
                // this condition is the crucial one. PAY ATTENTION.
            } else return false;
        } else return r1==r2;
    }
    bool isSymmetric(TreeNode* root) {
        return root == NULL || check(root->left,root->right);
    }
};