#include<stdio.h>
// App1 : Brute Force -> O(N^3)
// App2 : Optimised Brute Force -> O(N^2) (Have a look at this)
// App3 : Two Traversals -> O(N)
// App4 : Kadane's Algo -> O(N) single Traversal


// I didn't understood Kadane's logic so please do it later

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int maxLeft=INT_MIN,maxRight=INT_MIN;
        for(int i: nums) {
            prod*=i;
            maxLeft = max(maxLeft,prod);
            if(i==0) prod=1;
        }
        prod=1;
        for(int i=n-1;i>=0;i--) {
            prod*=nums[i];
            maxRight=max(maxRight,prod);
            if(nums[i]==0) prod=1;
        }
        return max(maxLeft,maxRight);
    }
};