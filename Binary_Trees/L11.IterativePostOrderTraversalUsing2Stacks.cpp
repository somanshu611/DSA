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

// I think that the approach of inserting elements in stack in this particular fashion is basically 
// inspired from recursion. It's like reverse enigneering. Study the recursion code, and then cleverly
// simulate the process using manual stack.
// Try Dry running the recursive code for postOrderTraversal, and see how the recursive calls
// are processed and pushed into the stack. 

// You must be thinking that first we should insert left and then right, because stack works in
// LIFO manner but we are reverse engineering here. In order to really understand, just dry run 
// the recursive approach, write down the post order traversal, and then think of how we can 
// transfer nodes from one stack to another. You probably won't be able to get it, if you haven't
// seen striver's dry running of his approach first, and then analyse yourself why it works.

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1,st2;
        vector<int> ans;
        st1.push(root);
        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            st1.push(node->left);
            st1.push(node->right);
        }
        while(!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};
// Space Complexity : O(2N)
// TC : O(N)