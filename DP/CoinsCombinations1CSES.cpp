#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007

bool solve() {
    int n,x;
    cin>>n>>x;
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++) {
        for(int j=1;j<=n;j++) {
            if(i-c[j]>=0) dp[i]=(dp[i]+dp[i-c[j]])%MOD;
        }
    }
    cout<<dp[x]<<'\n';
 
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