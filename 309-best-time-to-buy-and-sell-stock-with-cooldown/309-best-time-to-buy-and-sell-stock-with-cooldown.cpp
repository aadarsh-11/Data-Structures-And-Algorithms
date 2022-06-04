class Solution {
public:
    int f(int i, int trans, vector<int> &prices, vector<vector<int>>& dp)
    {
        if(i >= prices.size()) return 0;
        
        if(dp[i][trans] != -1) return dp[i][trans];
        if(trans % 2)
        {
            return dp[i][trans] = max(prices[i] + f(i+2, trans+1, prices, dp), f(i+1,trans, prices,dp));
        }
        return dp[i][trans] = max(-prices[i] + f(i+1, trans+1, prices, dp), f(i+1, trans,prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,prices, dp);
    }
};