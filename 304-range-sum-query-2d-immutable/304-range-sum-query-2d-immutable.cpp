class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m));
        
        dp[0][0] = matrix[0][0];
        for(int i = 1 ; i<m; i++)
        {
            dp[0][i] = dp[0][i-1] + matrix[0][i];
        }
        
        for(int i = 1 ; i<n; i++)
        {
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
            }
        }
            
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = dp[row2][col2];
        if(row1 > 0) ans -= dp[row1-1][col2];
        if(col1 > 0) ans -= dp[row2][col1-1];
        if(row1 > 0 and col1 > 0) ans += dp[row1-1][col1-1];
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */