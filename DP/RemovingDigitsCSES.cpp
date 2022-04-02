#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007

// First Hand Observations : 
// 1<=n<1e6 -> this means that it will be difficult to have 2d dp, probably we'll have to use 1d dp.

// DP STATE DEFINTION :
// dp[i] = Minimum no. of ways to reach 0 from number 'i'.


// Let dig[] we a array containing digits of a number 'i'.

// RECURRENCE RELATION : 
// dp[i] = min( dp[i-dig[0]]+1,dp[i-dig[1]]+1,dp[i-dig[2]]+1,dp[i-dig[3]]+1,....)

// I assumed that we should consider both the possibility of deleting any one of the 2 digits.

// However, considering only the max digit works. 

bool solve() {
  int n;
  cin>>n;
  vector<int> dp(n+5,0);
  for(int i=1;i<=n;i++) {
        int num=i;
        int mx=0;
        while(num) {
            int d=num%10;
            num/=10;
            mx=max(d,mx);
        }
        dp[i]=dp[i-mx]+1;
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