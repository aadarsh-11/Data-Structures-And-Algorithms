class Solution {
public:
    
    int f(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        // cout<<i<<" "<<j<<endl;
        if(j < 0) return 1;
        else if(i<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j])
        {
            ans = f(s,t,i-1,j-1, dp) + f(s,t,i-1,j,dp);
        }
        else
        {
            ans = f(s,t,i-1,j,dp);
        }
        // cout<<ans<<endl;
        return dp[i][j] = ans;
    }
    
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return f(s,t,n-1,m-1, dp);
    }
};