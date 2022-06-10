#include<bits/stdc++.h>
using namespace std;

// TC = O(N+E){dfs}
// SC = O(2N){2 visited arrays}
// Auxially SC(ASC) = O(N){stack for recursive dfs calls}

bool dfs(vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &dfsvis,int i) {
    vis[i]=1;
    dfsvis[i]=1;
    for(auto &c: adj[i]) {
        if(!vis[c]) {
            if(dfs(adj,vis,dfsvis,c)) return true;
        } else if(dfsvis[c]) return true; 
        // else if(vis[c] && dfsvis[c]) return true; // the first condition(vis[c]) is not required
        // because if dfsvis[c] is true then defnitely vis[c] would be true. 
    }
    dfsvis[i]=0;
    return false;
}

int main() {
    int n,m;cin>>n>>m;// n->nodes, m->vertices
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<bool> vis(n+1,0);
    vector<bool> dfsvis(n+1,0);
    bool flag=false;
    for(int i=1;i<=n;i++) {
        if(vis[i]==0) {
            if(dfs(adj,vis,dfsvis,i)) {
                flag=true;
                break;
            }
        }
    }
    if(flag) cout<<"Cycle detected"<<'\n';
    else cout<<"NO Cycle "<<'\n';
    return 0;
}
// 9 10
// 1 2
// 2 3
// 3 4
// 3 6 
// 4 5
// 6 5
// 7 2
// 7 8
// 8 9
// 9 7
