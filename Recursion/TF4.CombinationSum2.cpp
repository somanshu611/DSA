// Here, we can't pick a coin again, this is the difference from combination
// sum 1. 
// Also, we won't be doing pick, not pick binary choice tree. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool flag=true;
    vector<vector<int>> ans={};
    void cs(vector<int>& cand,vector<int> v, int target, int idx=0) {
        if(target==0) {
            ans.push_back(v);
        }
        int n = cand.size();
        int prev = -1;
        for(int i=idx+1;i<n;i++) {
            if((target-cand[i])<0) break;
            if(cand[i]!=prev) {
                prev=cand[i];
                vector<int> temp=v;
                temp.push_back(cand[i]);
                cs(cand,temp,target-cand[i],i);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector<int> v={};
        cs(cand,v,target,-1);
        return ans;
    }
};