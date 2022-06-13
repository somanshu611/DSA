#include<bits/stdc++.h>
using namespace std;

// IMP : Learn another approah of using flagvectors as bitmask. 
// https://leetcode.com/problems/n-queens/discuss/19808/Accepted-4ms-c%2B%2B-solution-use-backtracking-and-bitmask-easy-understand.

// After placing a queen in a row,we trace back to see if there's any way the queen we've
// placed is getting in the way of another queen. We do that by searching daigonally(left & right)
// and straight vertically in the grid from row=0 till (current row-1). 
class Solution {
public:
    vector<vector<string>> ans;
    bool check(vector<string> &maze,int n,int r,int c) {
        int k=c-1;
        for(int i=r-1;i>=0;i--) { // left upper daigoanl
            if(k<0) break;
            if(maze[i][k]=='Q') return false;
            k--;
        }
        k=c+1;
        for(int i=r-1;i>=0;i--) { // right upper daigoanl
            if(k==n) break;
            if(maze[i][k]=='Q') return false;
            k++;
        }
        for(int i=r-1;i>=0;i--) { // straight vertical
            if(maze[i][c]=='Q') return false;
        }
        return true;
    }
    void nq(vector<string> &maze,int n,int row) {
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<maze[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        // cout<<"---------------"<<'\n';
        if(row==n) {
            ans.push_back(maze);
            return;
        }
        for(int i=0;i<n;i++) {
            if(maze[row][i]=='.') {
                if(check(maze,n,row,i)) {
                    maze[row][i]='Q';
                    nq(maze,n,row+1);
                    maze[row][i]='.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++) s+='.';
        vector<string> maze(n,s);
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<maze[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
        nq(maze,n,0);
        return ans;
    }
};