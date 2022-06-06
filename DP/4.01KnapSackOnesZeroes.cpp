#include<bits/stdc++.h>
using namespace std;

// This is just pure application of 0/1 knapsack and i've also space optimized to O(N X M) 
// instead of O(N X M X C). Here we have to keep two things into account 0s and 1s that's why
// O(N X M) is required. 

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<sz;i++) {
            int o=0,z=0;
            for(auto x: strs[i]) {
                if(x=='0') z++;
                else o++;
            }
            for(int j=m;j>=0;j--) {
                for(int k=n;k>=0;k--) {
                    if((j<z) || (k<o)) break;

                    dp[j][k] = max(dp[j][k],dp[j-z][k-o]+1);
                }
            }
        }
        return dp[m][n];
    }
};