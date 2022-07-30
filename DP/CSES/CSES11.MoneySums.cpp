#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007


// You have n coins with certain values. 
// Your task is to find all money sums you can create using these coins.

// 1≤n≤100
// 1≤xi≤1000











set<int> ans;
int n;
vector<int> arr;
vector<vector<int>> dp(105,vector<int>(100005,-1));
bool solve() {
    int n;cin>>n;
    arr.resize(n+1);
    for(i=1;i<=n;i++) cin>>arr[i];
    dp[1][0]=0;
    for(i,1,n) {
        for(j,0,(int)100000) {
            if(dp[i][j]!=(-1)) {
                // cerr<<j<<","<<arr[j]<<" ";
                dp[i+1][j]=0;
                dp[i+1][j+arr[i]]=0;
            }
        }
        // cerr<<nl;
    }
    // debug(dp);
    for(i,1,(int)100000) {
        if(dp[n+1][i]!=-1) ans.insert(i);
    }
    cout<<ans.size()<<nl;
    for(auto &c: ans) cout<<c<<" ";
    cout<<nl;
 
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