class Solution {
public:
    int f(int l, vector<int>& a, vector<int>& b, vector<vector<int>>&dp, int i)
    {
        if(i == b.size()) return 0;
        if(dp[l][i] == INT_MAX)
        {
            int r = a.size()-1 - (i-l);
            dp[l][i] = max(a[l]*b[i] + f(l+1,a,b,dp,i+1), a[r]*b[i] + f(l,a,b,dp,i+1));
        }
        return dp[l][i];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp(1001,vector<int>(1001,INT_MAX));
        return f(0,nums,multipliers,dp, 0);
    }
};