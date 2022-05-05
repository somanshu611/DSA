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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l = 0,r=0;
        if((root->left)!=NULL) l = maxDepth(root->left);
        if((root->right)!=NULL) r = maxDepth(root->right);
        return max(l,r)+1;
    }
};

// Level Order Traversal Approach(Iterative Approach) : 
// If we use this approach, then space complexity will be O(n/2)=O(n),
// because at last level of complete binary tree, no. of nodes will be n/2.
// Complete binary tree is the worst case for this approach.

// Recursive Approach : 
// This will use Auxillary space of O(log(n)), but in case of a skewed tree, 
// this too will take O(n) space, however, this is not the case most often as said by
// striver.

// Both of these approaches have their worst cases or you can say their cons. 