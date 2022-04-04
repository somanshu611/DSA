/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Time & space complxity is same as of level order traversal.
// TC = SC = O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int k = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans={};
        if(root==NULL) return ans;
        bool flag = 0;
        while(true) {
            int s = q.size();
            if(s==0) break;
            vector<int> temp(0);
            while(s>0) {
                temp.push_back(q.front()->val);
                if((q.front()->left)!=NULL) {
                    q.push(q.front()->left);
                }
                if((q.front()->right)!=NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
                s--;
            }
            if(flag) reverse(temp.begin(),temp.end());
            flag = !flag;
            ans.push_back(temp);
        }        
        return ans;
    }
    
};