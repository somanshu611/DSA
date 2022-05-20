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

// APPROACH 1 : 
// Brute Force. Insert each node in O(n) in worst case of skewed tree.
// TC = O(N^2)
// SC = O(1)

// APPROACH 2 : 
// Sort the preorder, which will give us inorder because we've seen earlier that inorder of BST
// is always sorted. Now, you have inorder and preorder, through which you can create BST. We've
// done this before.
// TC = O(NlogN)+O(N)
// SC = O(N) 


// APPROACH 3 : Using the 'Check if BT is BST' logic, where each node has a range(lower_bound,upper_bound)
// however, here we only need upper bound.

// NOTE : the function implemented below requires pass by reference of 'i' of preorder vector.
// It is important because as we insert node into BST our 'i' will change, and thus if we use
// pass by value, the 'i' will not be updated. You can look my wrong submission where i debugged this
// by print statements, that will give you clarity to what i'm sayin here.



class Solution {
public:
    TreeNode* fun(int &i,vector<int> &preorder,int ub) {
        if(i>=preorder.size() || preorder[i]>=ub) return NULL;
        TreeNode* node = new TreeNode(preorder[i]);
        cout<<node->val<<" "<<ub<<'\n';
        i++;
        node->left = fun(i,preorder,node->val);
        node->right = fun(i,preorder,ub);
        return node;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0; // for pass by reference
        TreeNode* node = fun(i,preorder,1001);
        return node;
    }
};