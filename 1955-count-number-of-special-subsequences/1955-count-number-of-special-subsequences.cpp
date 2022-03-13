class Solution {
public:
    int countSpecialSubsequences(vector<int>& a) {
        int n = a.size();
        vector<int> dp(3,0);
        int mod = 1e9+7;
        for(int i = 0; i<n; i++)
        {
            if(a[i] == 0)
                dp[0] = (dp[0]*2 + 1)%mod;
            else if(a[i] == 1)
                dp[1] = ((dp[1]*2)%mod + dp[0])%mod;
            else
                dp[2] = ((dp[2] *2)%mod + dp[1])%mod;
        }
        return dp[2];
    }
};