// https://leetcode.com/problems/longest-consecutive-sequence/submissions/
// use of hash set(unordered_set)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &c: nums) {
            st.insert(c);
        }
        int mx = 0;
        while(!st.empty()) {
            int x,y;x=y=(*st.begin());
            x--;
            while(st.find(x)!=st.end()) {
                st.erase(x);
                x--;
            }
            x++;
            while(st.find(y)!=st.end()) {
                st.erase(y);
                y++;
            }
            y--;
            mx = max(mx,y-x+1);
        }
        return mx;
        
        
    }
};