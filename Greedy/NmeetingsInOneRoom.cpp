#include<bits/stdc++.h>
using namespace std;

// This solution is for gfg problem, however, on different platforms you'll find little differences
// that's why striver's code is imp, so do check that out below.
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) {
            v[i].first=end[i];
            v[i].second=start[i];
        }
        sort(v.begin(),v.end());
        int prev = 0,ans = 0;
        for(int i=0;i<n;i++) {
            if(v[i].second>prev) {
                prev=v[i].first;
                ans++;
            }
        }
        return ans;
    }
};

// Striver's code  : 
struct meeting {
    int start;
    int end;
    int pos;
};
bool comparator(meeting m1,meeting m2) {
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    else return false;
}

void maxMeetings(int s[],int e[],int n) {
    struct meeting meet[n];
    for(int i=0;i<n;i++) {
        meet[i].start = s[i];
        meet[i].end = e[i];
        meet[i].pos = i+1; // 1 based indexing of meetings
    }
    sort(meet,meet+n,comparator);
    vector<int> ans;
    int prev=-1;
    for(int i=0;i<n;i++) {
        if(meet[i].start>prev) {
            prev = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    for(int x: ans) cout<<x<<" ";
    cout<<'\n';
    
}