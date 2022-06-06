#include<bits/stdc++.h>
using namespace std;


// TC = O(N+E){dfs} + O(N){for loop}
// TC is not O(N*N) bcoz dfs is not run on each iteration. 
// SC = O(N+E){adj list} + O(N){visited array} + O(N){aux stack space}

// Scroll down below for example test cases

bool dfs(vector<vector<int>> &adj,vector<bool> &visited,int i,int parent) {
    visited[i]=1;
    for(auto &c: adj[i]) {
        if(c==parent) continue;
        if(visited[c]==0) {
            if(dfs(adj,visited,c,i)) return true;;
        } else return true;
    }
    return false;
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
    bool flag=false;
    for(int i=1;i<=n;i++) {
        if(visited[i]==0) {
            if(dfs(adj,visited,i,-1)) {
                flag=true;
                break;
            } 
        }
    }
    if(flag) cout<<"Cycle Detected"<<'\n';
    else cout<<"Given Graph has no cycle"<<'\n';

    return 0;
}
// 8 7
// 1 3
// 3 4
// 2 3 
// 3 8
// 8 7 
// 7 6
// 6 3
