class Solution {
public:
    
    bool rec(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp)
    {
        if(k<0) return 1;
        if(i<0 and j<0) return 0;
        
        if(dp[i+1][j+1][k+1] != -1) return dp[i+1][j+1][k+1];
        
        if(i>=0 and j>=0)
        {
            if(s1[i] == s3[k] and s2[j] == s3[k])
                return dp[i+1][j+1][k+1] = rec(s1,s2,s3,i-1,j,k-1,dp) or rec(s1,s2,s3,i,j-1,k-1,dp);
            if(s1[i] == s3[k])
                return dp[i+1][j+1][k+1] = rec(s1,s2,s3,i-1,j,k-1,dp);
            if(s2[j] == s3[k])
                return dp[i+1][j+1][k+1] = rec(s1,s2,s3,i,j-1,k-1,dp);
        }
        if(i>=0)
        {
            if(s1[i] == s3[k])
                return dp[i+1][j+1][k+1] = rec(s1,s2,s3,i-1,j,k-1,dp);
        }
        else
        {
            if(s2[j] == s3[k])
                return dp[i+1][j+1][k+1] = rec(s1,s2,s3,i,j-1,k-1,dp);
        }
        return dp[i+1][j+1][k+1] = 0;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int l = s3.size();
        
        if(l != n+m) return 0;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(l+1,-1)));
        
        return rec(s1,s2,s3,n-1,m-1,l-1,dp);
    }
};