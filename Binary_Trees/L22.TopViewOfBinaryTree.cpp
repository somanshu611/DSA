#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// THIS IS A GFG PROBLEM.

// For this problem, the logic is that for each vertical(from Vertical Order Traversal) 
// we need to print the topmmost/firstmost
// element. If we do any traversal other than Level order, then we'll have to keep account
// of both row and column index of each node, however, for level order traversal  we only
// need take account of column number, and since we are going rows wise(level wise), we will
// take the first element that occurs for any vertical and not take the later one.

// Here the iterative approach is very intuitive and easy to implement, in recursive
// approach you'll have to keep account of height/row and implement a logic for that
// which is unneccessary.


// For first approach, i tried using InOrderTraversal but that was super dumb, because
// i need to keep account of row too for that.
// Also this code is not completed and is wrong.


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,int> mp;
        stack<pair<Node*,pair<int,int>>> st;
        // stack.push({root,{0,0}});
        pair<Node*,pair<int,int>> curr = {root,{0,0}};
        while(!st.empty()) {
            if(curr.first!=NULL) {
                st.push(curr);
                curr = {curr.first->left,{curr.second.first+1,curr.second.second-1}};
            } else {
                Node* node = st.top().first;
                int r = st.top().second.first;
                int c = st.top().second.second;
                st.pop();
                if(mp.count(c)==0) mp[c]=node->data;
                
                st.push({node->right,{r+1,c+1}});
            }
        }
        for(auto &c: mp) {
            ans.push_back(c.second);
        }
        return ans;
    }

};

// for this solution you don't need to take account the row number, because we are doing
// Level Order TRaversal.

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        queue<pair<Node*,pair<int,int>>> q;
        q.push({root,{0,0}});
        // cout<<"Hello"<<'\n';
        map<int,int> mp;
        while(!q.empty()) {
            int s = q.size();
            while(s>0) {
                Node* node = q.front().first;
                int r = q.front().second.first;
                int c = q.front().second.second;
                // cout<<node->data<<endl;
                q.pop();
                if(mp.count(c)==0) mp[c] = node->data;
                if(node->left!=NULL) q.push({node->left,{r+1,c-1}});
                if(node->right!=NULL) q.push({node->right,{r+1,c+1}});
                s--;
            }
        }
        for(auto c: mp) {
            ans.push_back(c.second);
        }
        return ans;
    }

};
