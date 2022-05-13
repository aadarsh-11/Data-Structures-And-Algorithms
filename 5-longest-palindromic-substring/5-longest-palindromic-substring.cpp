class Solution {
public:
    string longestPalindrome(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        pair<int,int> maxl = {0,0};
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(s[i-1] == t[j-1])
                {
                    if(dp[i-1][j-1] > 0)
                    {
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
                    if(dp[i][j] > dp[maxl.first][maxl.second] and i-dp[i][j] == n-j)
                    {
                        maxl = {i,j};
                    }
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        int len = dp[maxl.first][maxl.second];
        string ans = s.substr(maxl.first - len,len);
        return ans;
    }
};