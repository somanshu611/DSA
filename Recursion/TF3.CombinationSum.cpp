#include<bits\stdc++.h>
using namespace std;

// Here we have a binary choice tree. 
// Here we can pick a coin again and again, unlike combination sum 2

// This is exactly like cses problem, and i imagine pep coding combination sum
// where i had written an array and had simulated the whole process of dp code.
// Here, the idea is to capitalise on sorted array. Let's say we take 2, then 
// it's possible that there must be distinct combination which again uses 2.
// But let's say we take 3 which is greater than 2, then we won't be taking 
// 2 again. Why? So to ensure that our pick is distinct. We are picking in order. 
// WE ARE ONLY TAKING SORTED COMBINATIONS, if that makes sense. 

// [2,2,3]
// [2,3,2]
// [3,2,2] -> [2,2,3], we only take this in our algorithm.

// Also, this approach is kinda similar to subsetsum2 by striver. 

class Solution {
public:
    bool flag=true;
    vector<vector<int>> combinationSum(vector<int>& cand, int total,int idx = 0) {
        if(flag) { // so that we sort only once
            flag=false;
            sort(cand.begin(),cand.end());
        }
        int n = cand.size();
        if(total==0) {
            vector<vector<int>> arr= {{}};
            return arr;
        }
        vector<vector<int>> ans;
        for(int i=idx;i<n;i++) {
            if(total-cand[i]<0) break;
            vector<vector<int>> arr = combinationSum(cand,total-cand[i],i);
            for(auto y: arr) {
                y.push_back(cand[i]);
                ans.push_back(y);
            }
        }
        return ans;
    }
};