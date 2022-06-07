#include<bits/stdc++.h>
using namespace std;


// TC = O(N){dfs} + O(N){for loop}
// TC is not O(N*N) bcoz dfs is not run on each iteration. 
// SC = O(N+E){adj list} + O(N){visited array}

vector<int> _dfs;// Here, unlike BFS i just took a 1D array for storing the answer, which stores the whole
// traversal. 
// Scroll down below for example test cases

void dfs(vector<vector<int>> &adj,vector<bool> &visited,int i) {
    _dfs.push_back(i);
    visited[i]=1;
    for(auto &c: adj[i]) {
        if(visited[c]==0) {
            dfs(adj,visited,c);
        }
    }
}
int main() {
    int n,m;cin>>n>>m;// n->nodes, m->vertices
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1,0);
    for(int i=1;i<=n;i++) {
        if(visited[i]==0) {
            dfs(adj,visited,i);
        }
    }

    for(auto &x: _dfs) cout<<x<<" ";
    cout<<'\n';

    return 0;
}
// 7 6 
// 1 2
// 2 4 
// 2 7 
// 7 6 
// 6 4
// 3 5

