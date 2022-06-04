class Solution {
public:
    int f(int i, int trans, vector<int> &prices, vector<vector<int>>& dp, int k)
    {
        if(i == prices.size() or trans == 2*k) return 0;
        
        if(dp[i][trans] != -1) return dp[i][trans];
        if(trans % 2)
        {
            return dp[i][trans] = max(prices[i] + f(i+1, trans+1, prices, dp, k), f(i+1,trans, prices,dp, k));
        }
        return dp[i][trans] = max(-prices[i] + f(i+1, trans+1, prices, dp, k), f(i+1, trans,prices, dp, k));
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k,-1));
        return f(0,0,prices, dp, k);
    }
};