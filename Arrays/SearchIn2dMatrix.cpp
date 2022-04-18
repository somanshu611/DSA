// link : https://leetcode.com/problems/search-a-2d-matrix/

// Approach 1 : 
// Using Binary Search on Column, but because we have a 2d array, we need to use manual BS.
// And then using lower_bound on that row, which we found manually that contains the answer.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int l = 0,h = n-1,mid;
        while(l<=h) {
            mid = (l+h)/2;
            cout<<l<<" "<<h<<'\n';
            if(matrix[mid][0]==target) return true;
            if(matrix[mid][0]<target) {
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        cout<<mid<<'\n';
        auto itr = lower_bound(matrix[mid].begin(),matrix[mid].end(),target);
        if(itr==matrix[mid].end()) return false;
        int val = *itr;
        if(val==target) return true;
        else return false;
        
    }
};

// Approach 2 : 
// This was implemented by me, however, I indexed l = 1, h = m*n;
// But, indexing l = 0 and h= m*n-1, is much more better as it somehow requrires less
// conditions because of the way modulo works.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m=matrix[0].size();
        int l = 1,h = (n*m);
        // cout<<l<<" "<<h<<'\n';
        int mid;
        while(l<=h) {
            mid = l+(h-l)/2;
            // cout<<"mid="<<mid<<'\n';
            int r = (mid%m)==0 ? (mid/m)-1 : mid/m;
            int c = mid - r*m - 1;
            // cout<<matrix[r][c]<<'\n';
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target) h=mid-1;
            else l = mid+1;
        }
        return false;
        
    }
};

// Approach 2 but just with more efficient code/logic.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m=matrix[0].size();
        int l = 0,h = (n*m)-1;
        cout<<l<<" "<<h<<'\n';
        int mid;
        while(l<=h) {
            mid = l+(h-l)/2;
            cout<<"mid="<<mid<<'\n';
            int r = mid/m;
            int c = mid%m;
            cout<<matrix[r][c]<<'\n';
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target) h=mid-1;
            else l = mid+1;
        }
        return false;
        
    }
};
