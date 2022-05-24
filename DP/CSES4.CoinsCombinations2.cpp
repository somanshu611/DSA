#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007
// PROBLEM : Consider a money system consisting of n coins. Each coin has a positive integer value. 
// Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the 
// available coins.

// For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
// 2+2+5
// 3+3+3
// 2+2+2+3

// SOLUTION : 
// This is a classical 0/1 knapsack style problem.
// Distint ordered ways is the key here.

// How do we ensure that all the repeated ways are not counted as different and only counted once? 

// There a trick(a logical way) to do that. We can pick coins in order(like first all 2Rs coins, 
// then 3Rs coins, and so on...) so that, we don't choose that coin again after picking coins of another denomination.
// What i mean is that this shouldn't happen : 2,2,3,2(Picking 2 after 3)
// We are doing this so that we can get DISTINCT ORDERED WAYS. Picking coins in order
// helps us to not have repeated ways like in CoinsCombination1.

// 2,3,2
// 2,2,3
// 3,2,2 // These are all same ways just the order is different.
// We can have just one way that represents all these ways : 
// i.e -> 2,2,3

// DP STATE DEFINITION : 
// dp[i][x] = No. of ways to make sum 'x' from first 'i' coins.

// As i mentioned in the beginning, we need to pick in order, for distinct ways. How do we do that?
// First, we either a pick a coin or we don't. If we do, then, we can pick that coin again, until we decide not to. After we 
// are done picking certain no. of coins of certain denomination, then we move on to pick the coin of next denomination. This also means that we won't pick that coin of earlier denomination again.

// If we choose not to pick a coin, then there's a possibility that other denominations might give our desired sum.

// Now, our total number of ways is just sum of these two possibilies.

// We can write this in recurrence relation like this :

// RECURRENCE RELATION : 
// dp[i][x] = dp[i-1][x](we don't pick a coin)+dp[i][x-c](we pick a coin)

bool solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=x;j++) {
            dp[i][j]=dp[i-1][j];
            if( (j-a[i])>=0) dp[i][j] = (dp[i][j]+dp[i][j-a[i]])%MOD;
        }
    }
    cout<<dp[n][x]<<'\n';
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