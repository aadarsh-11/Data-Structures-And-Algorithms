class Solution {
public:
    int rec(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if(i == s1.size()) return s2.size()-j;
        if(j == s2.size()) return s1.size()-i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return rec(s1,s2,i+1,j+1, dp);
        return dp[i][j] = 1 + min(rec(s1,s2,i+1,j,dp), rec(s1,s2,i,j+1,dp));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        
        return rec(word1,word2,0,0,dp);
    }
};