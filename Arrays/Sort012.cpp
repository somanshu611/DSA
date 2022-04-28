// https://leetcode.com/problems/sort-colors/

// Approach 1 : Two pass algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return;
        int e = n-1,i=0;
        while(i<e) {
            if(nums[i]==2) {
                swap(nums[i],nums[e]);
                e--;
            } else {
                i++;
            }
        }
        while((e>=0) && (nums[e]==2)) e--;
        i = 0;
        while(i<e) {
            if(nums[i]==1) {
                swap(nums[i],nums[e]);
                e--;
            } else {
                i++;
            }
        }
        
    }
};


// Approach 2 : 
// Dutch Nationa Flag algorithm