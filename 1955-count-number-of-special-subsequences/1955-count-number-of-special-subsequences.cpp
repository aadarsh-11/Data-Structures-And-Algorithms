class Solution {
public:
    int countSpecialSubsequences(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(3,0));
        int mod = 1e9+7;
        for(int i = 0; i<n; i++)
        {
            if(i == 0)
            {
                if(a[i] == 0)
                dp[i][0] = 1;
                continue;
            }
            if(a[i] == 0)
            {
                if(dp[i-1][0] == 0)
                    dp[i][0] = (dp[i-1][0]+1)%mod;
                else
                    dp[i][0] = ((dp[i-1][0] +1) *2 -1)%mod;
                
                dp[i][1] = dp[i-1][1];
                dp[i][2] = dp[i-1][2];
            }
            else if(a[i] == 1)
            {
                dp[i][1] = ((dp[i-1][1]*2)%mod + dp[i-1][0])%mod;
                dp[i][0] = dp[i-1][0];
                dp[i][2] = dp[i-1][2];
            }
            else
            {
                dp[i][2] = ((dp[i-1][2] *2)%mod + dp[i-1][1])%mod;
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
        }
        return dp[n-1][2];
    }
};