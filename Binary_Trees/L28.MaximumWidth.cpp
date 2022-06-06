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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty()) {
            int s = q.size();
            int l = q.front().second;
            int h;
            long long k = l;
            while(s--) {
                TreeNode* node = q.front().first;
                long long i = q.front().second;
                if(s==0) h=i;
                q.pop();
                if(node->left!=NULL) {
                    q.push({node->left,(i-k)*2+1});
                }
                if(node->right!=NULL) {
                    q.push({node->right,(i-k)*2+2});
                }
            }
            ans = max(ans,(h-l+1));
        }
        return ans;
    }
};