class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int ans = 0;
        
        for(int i = n-1; i >=0 ; i--)
        {
            for(int j = i; j< n; j++)
            {
                if(i == j) dp[i][j] = 1;
                else if(i+1 == j)
                {
                    dp[i][j] = s[i] == s[j];
                }
                else
                {
                    dp[i][j] = (s[i] == s[j] and dp[i+1][j-1]);
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};