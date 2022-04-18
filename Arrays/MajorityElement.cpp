// link : https://leetcode.com/problems/majority-element/

// Approach 1 : Brute Force -> TC=O(n^2),SC=O(1)
// Approach 2 : Using Frequency Array or HashMap -> TC=O(NlogN),SC=O(n)

// Optimal Approach : 
// Approach 3 : Moore's Voting algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0,ele=-1;
        for(auto &c: nums) {
            if(cnt==0) ele=c;
            if(c==ele) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return ele;
    }
};