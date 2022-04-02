// Problem link : https://leetcode.com/problems/maximum-subarray/submissions/

// Maximum sub array sum problem.
// Solution by Kadane's algorithm.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int temp = 0;
        int n = nums.size();
        int l = 0,r = 0;
        while(r<n) {
            // cout<<l<<" "<<r<<'\n';
            
            if(temp<=0) {
                l = r;
                temp = nums[l];
                ans = max(ans,nums[l]);
            } else {
                temp += nums[r];
            }
            r++;
            ans = max(temp,ans); 
        }
        return ans;
    }
};