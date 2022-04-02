#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007

// This is EXACTLY 0/1 knapsack classical dp problem. NO difference.

// We have to maximise the number of pages. This falls in the pattern 1 of leetcode article.

// Constraints are very imp observations here. 
// 1<=x<=1e5, 

bool solve() {
    int n,x;
    cin>>n>>x;
    vector<int> h(n+1),s(n+1);
    for(int i=1;i<=n;i++) cin>>h[i]; // prices
    for(int i=1;i<=n;i++) cin>>s[i]; // pages 
    vector<vector<int>> dp(n+1,vector<int> (x+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=x;j++) {
            dp[i][j]=dp[i-1][j]; // not choosing the book
            if( (j-h[i]) >= 0) dp[i][j]=max( dp[i][j],dp[i-1][j-h[i]]+s[i] );
        }
    }
    cout<<dp[n][x]<<'\n';
 
    return 0;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}