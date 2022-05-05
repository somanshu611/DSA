// https://leetcode.com/problems/balanced-binary-tree/
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
    int dfsHeight(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh = dfsHeight(root->left);
        int rh = dfsHeight(root->right);
        if(lh==(-1) || rh==(-1)) return -1;
        if(abs(lh-rh)<=1) return max(lh,rh)+1;
        else return -1;
    }
    bool isBalanced(TreeNode* root) {
        if(dfsHeight(root)>=0) return true;
        else return false;
    }
};

// SC = O(N) -> Auxillary stack space will be O(N) for skewed tree(worst case)