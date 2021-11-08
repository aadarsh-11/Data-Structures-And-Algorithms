class Solution {
public:
    int dp[20];
    int numTrees(int n) {
        for(int i = 0 ; i < 20; i++)
            dp[i ]= -1;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        return rc(n);
    }
    int rc(int n)
    {
        if(dp[n] != -1)
            return dp[n];
        else
        {
            int ans = 0;
            for(int i = 0 ; i < n ; i ++)
            {
                ans += rc(i)*rc(n-i-1);
            }
            dp[n] = ans;
            return ans;
        }
    }
};