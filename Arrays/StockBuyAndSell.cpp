// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Better approach might be possible, check discuss section.

// SC = O(n)
// TC = O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =  prices.size();
        vector<int> mx(n),mn(n);
        mn[0]=prices[0];
        mx[n-1]=prices[n-1];
        for(int i=1;i<n;i++) {
            mn[i]=min(mn[i-1],prices[i]);
        }
        for(int i=n-2;i>=0;i--) {
            mx[i]=max(mx[i+1],prices[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans,mx[i]-mn[i]);
        }
        return ans;
    }
};