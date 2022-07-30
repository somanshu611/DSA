#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007

vector<vector<int>> dp(1e5+1,vector<int>(100+5,0));
bool solve() {
    int n,m;cin>>n>>m;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];

    if(arr[1]==0) {
        for(int i=1;i<=m;i++) {
            dp[1][i]=1;
        }
    } else {
        dp[1][arr[1]]=1;
    }
    for(int i=2;i<=n;i++) {
        if(arr[i]==0) {
            for(int j=1;j<=m;j++) {
                dp[i][j] = ((dp[i-1][j-1]+dp[i-1][j])%MOD + dp[i-1][j+1])%MOD;
            }
        } else {
            dp[i][arr[i]] = ((dp[i-1][arr[i]-1]+dp[i-1][arr[i]])%MOD + dp[i-1][arr[i]+1])%MOD;
        }
    }
    // for(int i=0;i<=n;i++) {
    //     for(int j=0;j<=m;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    int sum = 0;
    for(int i=1;i<=100;i++) {
        sum = (sum + dp[n][i])%MOD;    
    }
    cout<<sum<<'\n';
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