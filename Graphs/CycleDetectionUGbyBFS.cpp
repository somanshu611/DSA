#include<bits/stdc++.h>
using namespace std;

// Here too the parent logic applies and that is the only logic here. 

// TC = O(N+E)
// SC = O(2*N){queue} + O(N){visited array} + O(N+E) {adjacency list}

// Scroll down for example test cases


bool bfs(vector<vector<int>> &adj,vector<bool> &visited,int i) {
    queue<pair<int,int>> q;
    q.push({i,-1});
    visited[i]=1;
    while(true) {
        int s = q.size();
        if(s==0) break;
        bool flag=false;
        while(s--) {
            int x = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto &y: adj[x]) {
                if(y==parent) continue;
                if(visited[y]==0) {
                    visited[y]=1;
                    q.push({y,x});
                } else return true;
            }
        }
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
            if(bfs(adj,visited,i)) {
                flag=true;
                break;
            }
        }
    }
    if(flag) cout<<"Cycle Detected"<<'\n';
    else cout<<"No Cycle in Given Graph"<<'\n';

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

