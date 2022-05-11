class Solution {
public:
    int f(int n, int v, vector<vector<int>>&dp)
    {
        if(n == 1) return v;
        if(dp[n][v] != -1) return dp[n][v];
        int ans = 0;
        while(v>0)
        {
            ans += f(n-1,v--,dp);
        }
        return dp[n][v] = ans;
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(6,-1));
        return f(n,5,dp);
    }
};