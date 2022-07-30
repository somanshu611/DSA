// Problem link : https://cses.fi/problemset/task/1639
// Problem link : https://leetcode.com/problems/edit-distance/

#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007

// The edit distance between two strings is the minimum number of operations required to transform one string into the other.

// The allowed operations are:
// Add one character to the string.
// Remove one character from the string.
// Replace one character in the string.
// For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.

// Your task is to calculate the edit distance between two strings.


// Constraints
// 1≤n,m≤5000


































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