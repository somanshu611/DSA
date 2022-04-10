// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void print(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    void rotate(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};