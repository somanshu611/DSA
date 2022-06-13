#include<bits\stdc++.h>
using namespace std;

// sort the array first, so to avoid duplicates.
// Here, we don't have binary choice tree. And, also we are not calculating answers
// on leaf nodes, and instead on every node, every node is the answer and 
// contains unique subset. 

class Solution {
public:
    vector<vector<int>> ans ={{}};
    void subsets(int i,vector<int>& nums,vector<int> arr) {
        int n = nums.size();
        if(i==n) {
            return;
        }
        int prev = -1000;
        for(int j=i;j<n;j++) {
            if(nums[j]!=prev) {
                vector<int> temp = arr;
                temp.push_back(nums[j]);
                prev=nums[j];
                ans.push_back(temp);
                subsets(j+1,nums,temp);
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> a = {};
        subsets(0,nums,a);
        return ans;
    }
};