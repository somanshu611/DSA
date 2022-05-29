// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
// See question on leetcode for better understanding of (r,c) implementation.
// map<int,map<int,multiset<int>>> -> c,r,node_values (c before r before vertical order traversal)
// queue<pair<TreeNode*,pair<int,int>>

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> mp;
        while(!q.empty()) {
            int s = q.size();
            while(s>0) {
                TreeNode* node = q.front().first;
                int r = q.front().second.first;
                int c = q.front().second.second;
                q.pop();
                mp[c][r].insert(node->val); // NOTE : if you write [r][c] then it will give row wise 
                // traversal.
                if(node->left!=NULL) q.push({node->left,{r+1,c-1}});
                if(node->right!=NULL) q.push({node->right,{r+1,c+1}});
                s--;
            }
        }
        vector<vector<int>> ans;
        for(auto c: mp) {
            vector<int> temp;
            for(auto d: c.second) {
                for(auto e: d.second) {
                    temp.push_back(e);
                }
            }
            // sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};