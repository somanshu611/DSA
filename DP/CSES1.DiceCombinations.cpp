#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007

// Your task is to count the number of ways to construct sum n by 
// throwing a dice one or more times. 
// Each throw produces an outcome between 1 and 6.

// For example, if n=3, there are 4 ways:
// 1+1+1
// 1+2
// 2+1
// 3

// SOLUTION : 
// dp[i] = no. of ways dice can be thrown to make sum 'i'. 

// dp[i] = (dp[i-1]+dp[i-2]+...+dp[i-6])%mod ;
// if i<0 -> dp[i]=0, 
// if i==0 -> dp[i]=1; 

bool solve() {
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++) {
        int j=1;
        while( (i-j)>=0 && j<=6) {
            dp[i]=(dp[i]+dp[i-j])%MOD;
            j++;
        }
    }
    cout<<dp[n]<<"\n";
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

