class Solution {
public:
    
    int f(vector<vector<int>> &a, int row, int col, vector<map<int,int>> &dp)
    {
        if(row >= a.size()) return 0;
        
        if(dp[row].find(col) != dp[row].end()) return dp[row][col];
        return dp[row][col] = a[row][col] + min(f(a,row+1,col,dp), f(a,row+1,col+1,dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<map<int,int>> dp(triangle.size());
        return f(triangle,0,0, dp);
    }
};