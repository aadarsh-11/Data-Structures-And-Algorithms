class Solution {
public:
    
    int f(string &s, int i, vector<int> &dp)
    {
        if(i == s.size()) return 1;        
        if(s[i] == '0') return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int ans = f(s,i+1,dp);
        if(i+1 < s.size() and (s[i] < '2' or s[i] == '2' and s[i+1] <= '6'))
        {
            ans += f(s, i+2,dp);
        }
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {        
        vector<int> dp(s.size(), -1);
        return f(s,0, dp);
    }
};