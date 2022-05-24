#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

// PROBLEM : 
// Consider a money system consisting of n coins. Each coin has a positive integer value.
// Your task is to produce a sum of money x using the available coins in such a way that 
// the number of coins is minimal.

// For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 
// 5+5+1 which requires 3 coins.



// SOLUTION:
// dp[i] = Minimum no. of coins required to make sum 'i'.
// dp[i] = for(j=0;j<n;j++) : min(dp[i],dp[i-coins[j]]+1)
// Answer = dp[target], target is the sum required to make.
void solve() {
  int n,x;
  cin>>n>>x;
 
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
 
  vector<int> dp(x+5,-1);
  dp[0]=0;
 
  for(int i=1;i<=x;i++) {
      for(auto c: a) {
          if(i-c>=0) {
              if(dp[i]==-1 && dp[i-c]!=-1) {
                  dp[i]=dp[i-c]+1;
              } else if(dp[i-c]!=-1) dp[i]=min(dp[i],dp[i-c]+1);
          }
      }
  }
 
//   for(auto &c:dp) {
//       cout<<c<<" ";
//   }
//   cout<<"\n";
 
  cout<<dp[x]<<"\n";
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    fast_io;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}