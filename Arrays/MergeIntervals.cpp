// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    // debug(intervals);
    int n=intervals.size();
    vector<vector<int>> ans;
    int x=intervals[0][0],y=intervals[0][1];
    for(int i=1;i<n;i++) {
        if( (intervals[i][0]<=y) && (intervals[i][1]>=y) ) {
            y=intervals[i][1];
        } else if(intervals[i][1]<y) {

        } else {
            vector<int> ans2 = {x,y};
            ans.push_back(ans2);
            x = intervals[i][0];
            y = intervals[i][1];
        }
        if(i==(n-1)) {
            if(intervals[i][1]>=y) y = intervals[i][1];
            vector<int> ans2 = {x,y};
            ans.push_back(ans2);
        }
    }
    if(ans.size()==0) {
        vector<int> ans2 = {x,y};
        ans.push_back(ans2);
    }
    return ans;
}
};