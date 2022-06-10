#include<bits/stdc++.h>
using namespace std;

// TC = O(N+E){dfs}
// SC = O(N){visited array} + O(N){stack}
// Auxially SC(ASC) = O(N){stack for recursive dfs calls}

// See .txt file for this problem to understand the intuition behind this algo. 

// scroll down for example test case.

void dfs(vector<vector<int>> &adj,vector<bool> &vis,stack<int> &st,int i) {
    vis[i]=1;
    for(auto &c: adj[i]) {
        if(!vis[c]) {
            dfs(adj,vis,st,c);
        }
    }
    st.push(i); // the only difference between normal dfs and toposort dfs code
}

int main() {
    int n,m;cin>>n>>m;// n->nodes, m->vertices
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<bool> vis(n+1,0);
    stack<int> st;
    bool flag=false;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(adj,vis,st,i);
        }
    }
    vector<int> toposort;
    while(!st.empty()) {
        toposort.push_back(st.top());
        st.pop();
    }
    for(auto &x: toposort) {
        cout<<x<<" ";
    }
    cout<<'\n';
    return 0;
}
// 5 6
// 5 0
// 5 2
// 2 3
// 3 1 
// 4 0
// 4 1
