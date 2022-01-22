class Solution {
public:
    bool rec(vector<int>& dp, int n)
    {
        if(dp[n] != -1) return dp[n];
        
        bool ans = 0;
        
        for(int i = 1;n-i*i >=0; i++)
        {
            ans |= (1-rec(dp,n-i*i));
        }
        return dp[n] = ans;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        for(int i = 1; i*i <=n; i++)
        {
            dp[i*i] = 1;
        }
        bool ans = rec(dp,n);
        return ans;
    }
};