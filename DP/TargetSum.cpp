// Problem link : https://leetcode.com/problems/target-sum/
class Solution {
public:
    int find(vector<vector<int>> &dp,int i,int j,vector<int> &nums) {
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==0) return 0;
        int a=0,b=0;
        if((i-nums[j-1])>=0) a = find(dp,i-nums[j-1],j-1,nums);
        if((i+nums[j-1])<=2000) b = find(dp,i+nums[j-1],j-1,nums);
        dp[i][j]=a+b;
        return dp[i][j];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(2005,vector<int>(n+1,-1));
        dp[1000][0]=1;
        target +=1000;
        return find(dp,target,n,nums);
    }
};