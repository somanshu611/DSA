#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// The logic is inspired form Vertical Order Traversal. We do level order traversal,
// where each element of queue stores node and the vertical it belongs to. Since we want 
// bottom view, we want the last value of each vertical, so keep updating the value of 
// each vertical in std::map;

// For recursive approach we all have to keep track of height/row, which is unneccessary
// thus iterative approach is recommended.
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> mp;
        vector<int> ans;
        while(!q.empty()) {
            int s = q.size();
            while(s>0) {
                auto node = q.front();
                mp[node.second]=node.first->data;
                q.pop();
                if(node.first->left!=NULL) q.push({node.first->left,node.second-1});
                if(node.first->right!=NULL) q.push({node.first->right,node.second+1});
                s--;
            }
        }
        for(auto &c: mp) ans.push_back(c.second);
        return ans;
    }
};