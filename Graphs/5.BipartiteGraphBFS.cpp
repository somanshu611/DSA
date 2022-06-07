#include<bits/stdc++.h>
using namespace std;

// Definition : 
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
// OUr visited array need to be int, bcoz each node value in the visited array can be -1,0,1.
// -1 -> not visited
// 1 -> visited and color=1
// 0 -> visited and color=0



// TC = O(N+E){BFS}
// SC = O(N){queue} + O(N){visited/color array} + O(N+E) {adjacency list}

 
bool bfs(vector<vector<int>> &adj,vector<int> &visited,int i) {
    queue<int> q;
    q.push(i);
    visited[i]=0;
    // cout<<"Inside BFS"<<endl;
    while(true) {
        int s = q.size();
        if(s==0) break;
        while(s--) {
            int x = q.front();
            int color = visited[x];
            // cout<<x<<" "<<color<<endl;
            q.pop();
            for(auto &y: adj[x]) {
                if(visited[y]==(-1)) {
                    q.push(y);
                    visited[y] = color==1 ? 0 : 1;
                }
                if(visited[y]!=color) continue;
                else return false;
            }
        }
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
            if(bfs(adj,visited,i)==false) {
                flag=false;
                break;
            }
        }
    }
    if(flag) cout<<"Given Graph is Bipartite"<<endl;
    else cout<<"Not Bipartite"<<endl;

    return 0;
}
// Even length Cycle graph Example : 
// 8 8 
// 1 2
// 2 3
// 2 7
// 7 6
// 6 5
// 3 4
// 4 5 
// 5 8 

// Odd Length Cycle graph Example : 
// 4 4
// 1 2
// 2 3
// 2 4
// 3 4
