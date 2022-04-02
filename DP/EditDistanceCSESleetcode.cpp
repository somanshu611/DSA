// Problem link : https://cses.fi/problemset/task/1639
// Problem link : https://leetcode.com/problems/edit-distance/

#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007

bool solve() {
    string s,t;cin>>s>>t; 
    int n = s.size(),m=t.size();
    vector<vector<int>> dp(n+5,vector<int>(m+5,1e7));

    for(int i=0;i<=m;i++) {
        dp[n][i] = m-i;
    }
    for(int i=0;i<=n;i++) {
        dp[i][m]=n-i;
    }
    for(int i=n-1;i>=0;i--) {
        for(int j=m-1;j>=0;j--) {
            if(s[i]==t[j]) dp[i][j] = dp[i+1][j+1];
            else dp[i][j] = min(dp[i+1][j+1]+1,dp[i+1][j]+1,dp[i][j+1]+1);
        }
    }
    cout<<dp[0][0]<<'\n';
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