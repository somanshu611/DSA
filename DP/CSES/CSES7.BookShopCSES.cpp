#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000007

// You are in a book shop which sells n different books. 
// You know the price and number of pages of each book.

// You have decided that the total price of your purchases will be at most x. 
// What is the maximum number of pages you can buy? 
// You can buy each book at most once.

// 1≤n≤1000
// 1≤x≤10^5
// 1≤hi,si≤1000

















// This is EXACTLY 0/1 knapsack classical dp problem. NO difference.

// We have to maximise the number of pages for given price x. 
// This falls in the pattern 1 of leetcode article.

// 1. Dp state definition : dp[i][j] = maximum pages you can purchase with price 'x'.
// 2. Final answer : dp[n][x]
// 3. recurrence relation : dp[i][j] = max(dp[i-1][j],dp[i-1][j-h[i]]+s[i])

// Constraints are very imp observations here. 
// 1<=x<=1e5, 



bool solve() { // 2d dp typical solution.
    int n,x;
    cin>>n>>x;
    vector<int> h(n+1),s(n+1);
    for(int i=1;i<=n;i++) cin>>h[i]; // prices/weight
    for(int i=1;i<=n;i++) cin>>s[i]; // pages/val
    vector<vector<int>> dp(n+1,vector<int> (x+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=x;j++) {
            dp[i][j]=dp[i-1][j]; // not choosing the book
            if( (j-h[i]) >= 0) dp[i][j]=max( dp[i][j],dp[i-1][j-h[i]]+s[i] );
        }
    }
    cout<<dp[n][x]<<'\n';
    return 0;
}

// FOR SPACE OPTIMIZATION I HAD WATCHED STIVER'S VIDEO ON 0/1 KNAPSACK, and I didn't focus
// on his entire solution but only the part where he talked about space optimization, and he 
// gave me clear hints(more like solution XD) to what can be done, so i implemented on that. 

// So basically space optimization is done on the basis of recurrence relation. Here,
// we can see that for calculating the value of current state we need only one row
// before's value. Thus, we need only two rows, where our prev row/vector will
// work as dp array.
bool solve() { // use of only two vectors/rows
    int n,x;
    cin>>n>>x;
    vector<int> h(n+1),s(n+1);
    for(int i=1;i<=n;i++) cin>>h[i]; // prices
    for(int i=1;i<=n;i++) cin>>s[i]; // pages 
    vector<int> prev(x+1,0),cur(x+1,0);
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=x;j++) {
            cur[j] = prev[j];
            if(j-h[i]>=0) cur[j] = max(cur[j],prev[j-h[i]]+s[i]);
        }
        prev = cur;
    }
    cout<<cur[x]<<'\n';
    return 0;
}
// We can further optimize space to 1 vector only. We need to really focus and observe 
// on our implementation and recurrence relation. In our just above code, can we only use prev
// vector for every calculation? If we start our iteration from backwards for each item, 
// then our prev array will already storing values of i-1th item, and also we use left 
// of ith element to calculate our ith value, so the right most array remains useless. (I'M
// UNABLE TO EXPLAIN, PLEASE LOOK AT CODE FOR THIS, IT WAS KINDA INTUITIVE FOR ME AFTER 
// SEEING A BIT OF HINTS.)

bool solve() { // use of only 1 vector, SC = O(N), TC = O(N X M)
    int n,x;
    cin>>n>>x;
    vector<int> h(n+1),s(n+1);
    for(int i=1;i<=n;i++) cin>>h[i]; // prices
    for(int i=1;i<=n;i++) cin>>s[i]; // pages 
    vector<int> prev(x+1,0);
    for(int i=1;i<=n;i++) {
        for(int j=x;j>=0;j--) {
            if(j<h[i]) break;
            prev[j] = max(prev[j],prev[j-h[i]]+s[i]);
        }
    }
    cout<<prev[x]<<'\n';
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