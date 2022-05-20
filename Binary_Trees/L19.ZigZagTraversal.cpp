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

// Using queue for level order traversal.Run a loop till the size of the queue,
// and keep pushing left and rightelements into queuelike we do in level order traversal.
// And push back value of the elements that are popped into a temp array. 
// Keep a flag, if true, reverse the temp array 
// and push back to the answer, and if not, then push back without reversing.
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