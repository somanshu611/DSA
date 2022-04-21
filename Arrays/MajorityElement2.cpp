// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=nums[0],b=0,c1=0,c2=0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]==a) {
                c1++;
            } else if(nums[i]==b) {
                c2++;
            } else if(c1==0) {
                a = nums[i];
                c1 = 1;
            } else if(c2==0) {
                b = nums[i];
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        c1=c2=0;
        for(int &c: nums) {
            if(a==c) c1++;
            else if(b==c) c2++;
        }
        if(c1>(n/3)) {
            ans.push_back(a);
        }
        if(c2>(n/3)) {
            ans.push_back(b);
        }
        return ans;
    }
};