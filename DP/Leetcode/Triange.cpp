#include<bits/stdc++.h>
using namespace std;

// The follow up to this problem was basically KNAPSACk O(N) SPACE OPTIMISATION PROBELM.

// dp state -> dp[j] = tri[i][j] + min(dp[j],dp[j+1])

// This is interview type solution where i didn't modify the input, however dp array isn't really
// required and we can just our input triangle for storing our dp state answers.
// The dp state would like this if you don't want to use O(n) extra space for dp array. 
// dp state -> tri[i][j] = tri[i][j] + min(tri[i+1][j],tri[i+1][j+1])
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<int> dp((n*(n+1))/2);
        for(int i=0;i<tri[n-1].size();i++) {
            dp[i]=tri[n-1][i];
        }
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<tri[i].size();j++) {
                dp[j] = tri[i][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};