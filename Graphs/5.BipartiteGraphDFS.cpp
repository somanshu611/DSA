#include<bits/stdc++.h>
using namespace std;

// Definition : (Same as in BipartiteGraphBFS.cpp)
// A graph whose set of vertices can be divided into 2 disjoint sets such that : 
// 1. Each vertex belongs to exactly one of the 2 sets.
// 2. Each edge connects vertices of 2 different sets. 

// Basically, a graph that can be colored using 2 colors such that no two adjacent nodes 
// have same color.

// In order to know whether a graph is bipartite or not, we can note an important obseration 
// that if a graph has an ODD LENGTH CYCLE then IT IS NOT A BIPARTITE, and if it doesn't have
// then it is a bipartite graph i.e. we have included both the conditions of having a graph
// without even having a cycle or having an cycle of even length. 

// NOTE : HERE IN THE IMPLEMENTATION 
// Our visited/color array need to be int, bcoz each node value in the visited array can be -1,0,1.
// -1 -> not visited
// 1 -> visited and color=1
// 0 -> visited and color=0

// TC = O(N+E){dfs} + O(N){for loop}
// TC is not O(N*N) bcoz dfs is not run on each iteration. 
// SC = O(N+E){adj list} + O(N){visited/color array} + O(N){aux stack space}

// Scroll down below for example test cases

bool bipartiteDFS(vector<vector<int>> &adj,vector<int> &visited,int i,int color) {
    visited[i]=color;
    for(auto &c: adj[i]) {
        if(visited[c]==-1) {
            if(!bipartiteDFS(adj,visited,c,color==1 ? 0 : 1)) return false;
        } else if(visited[c]==color) return false;

    }
    return true;
}
int main() {
    int n,m;cin>>n>>m;// n->nodes, m->vertices
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited(n+1,-1);
    bool flag=true;
    for(int i=1;i<=n;i++) {
        if(visited[i]==(-1)) {
            if(!bipartiteDFS(adj,visited,i,0)) {
                flag=false;
                break;
            }
        }
    }
    if(flag) cout<<"Bipartite Graph"<<'\n';
    else cout<<"Not Bipartite Graph"<<'\n';
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
