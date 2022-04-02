#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007
 
bool solve() {
    int a,b;cin>>a>>b ;
    vector<vector<int>> dp(a+5,vector<int>(b+5,INT_MAX));
    for(int i=1;i<=a;i++) {
        for(int j=1;j<=b;j++) {
            if(i==j) {
                dp[i][j]=0;
                continue;
            }
            for(int k=1;k<=i/2;k++) {
                dp[i][j] = min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
            }
            for(int k=1;k<=j/2;k++) {
                dp[i][j] = min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
            }
        }
    }
    
    cout<<dp[a][b]<<'\n';
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