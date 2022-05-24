#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007
// PROBLEM : 
// Consider a money system consisting of n coins. Each coin has a positive integer value. 
// Your task is to calculate the number of distinct ways you can produce a money sum x 
// using the available coins. 
// For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
// 2+2+5
// 2+5+2
// 5+2+2
// 3+3+3
// 2+2+2+3
// 2+2+3+2
// 2+3+2+2
// 3+2+2+2
// CONSTRAINTS : 
// 1<=n<=100,1<=x<=1e6, 1<=c[i]<=1e6
// SOLUTION :
// dp[i] = for(j=1 till n) dp[i] = (dp[i]+dp[i-c[j]])%mod;

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