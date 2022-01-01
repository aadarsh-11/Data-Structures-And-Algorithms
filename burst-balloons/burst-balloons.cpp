class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int k = 1; k<=n; k++)
        {
            for(int i = 0; i <=n-k; i++)
            {
                int j = i+k-1;
                for(int x = i; x <= j; x++)
                {
                    int l = 1, r = 1;
                    if(i != 0) l = a[i-1];
                    if(j != n-1) r = a[j+1];
                    
                    int bef = 0, aft = 0;
                    if(i != x)
                    {
                        bef = dp[i][x-1];
                    }
                    
                    if(j != x)
                    {
                        aft = dp[x+1][j];
                    }
                    dp[i][j] = max(dp[i][j], l*a[x]*r + aft+bef);
                }
            }
        }
        return dp[0][n-1];
    }
};