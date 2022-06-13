
#include<bits/stdc++.h>
using namespace std;
Solution {
public:
    vector<vector<string>> ans;
    void prt(string &s,vector<string> &v,int n,int idx) {
        if(idx==n) {
            bool flag=false;
            for(auto &c: v) {
                int m = c.size();
                flag=false;
                for(int i=0;i<m/2;i++) {
                    if(c[i]!=c[m-i-1]) {
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag==false) ans.push_back(v);
            return;
        }
        int m = v.size();
        v[m-1].push_back(s[idx]);
        prt(s,v,n,idx+1);
        v[m-1].pop_back();
        string x = "";
        x.push_back(s[idx]);
        v.push_back(x);
        prt(s,v,n,idx+1);
        v.pop_back();
    }
    vector<vector<string>> partition(string s) {
        string x="";
        x.push_back(s[0]);
        vector<string> v;
        v.push_back(x);
        prt(s,v,s.size(),1);
        return ans;
        
    }
};