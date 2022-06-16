class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        
        int maxlen = 1;
        int ind = 1;
        
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(s[i-1] == s[n-j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                if(dp[i][j] > maxlen and i-dp[i][j] == n-j)
                {
                    maxlen = dp[i][j];
                    ind = i;
                }
            }
        }
        
        return s.substr(ind - maxlen, maxlen);
    }
};