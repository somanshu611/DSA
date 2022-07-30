#include<bits/stdc++.h>
using namespace std;
// BFS in a graph means visiting all adjacent nodes of a node first, and then moving onto
// next nodes. 
// We make use of queue here too, like in trees. 

// Also i ran this code in terminal without input.txt, and it works great. 

// TC = O(N+E)
// SC = O(N){queue} + O(N){visited array} + O(N+E) {adjacency list}


vector<vector<int>> traversals; // Each traversal will give a connected component. Size of
// vector is the number of connected components in graph. 
// Also, instead of this you can also keep a vector<int> bfs which would store the whole 
// traversal, this is what striver did. 
void bfs(vector<vector<int>> &adj,vector<bool> &visited,int i) {
    queue<int> q;
    q.push(i);
    visited[i]=1;
    vector<int> ans = {};
    while(true) {
        int s = q.size();
        if(s==0) break;
        while(s--) {

            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto &y: adj[x]) {
                if(visited[y]==0) {
                    visited[y]=1;
                    q.push(y);
                }
            }
        }
    }
    traversals.push_back(ans);

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
            bfs(adj,visited,i);
        }
    }

    for(auto &x: traversals) {
        for(auto &y: x) {
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}
// 7 6 
// 1 2
// 2 4 
// 2 7 
// 7 6 
// 6 4
// 3 5

