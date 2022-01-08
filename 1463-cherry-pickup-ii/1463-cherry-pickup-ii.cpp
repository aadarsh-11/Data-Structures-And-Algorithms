class Solution {
public:
    int dp[70][70][70] = {-1};
    
    int dfs(vector<vector<int>> &g, int m, int n, int r, int c1, int c2)
    {
        if(r == m) return 0;
        
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int ans =0;
        for(int i = -1; i<=1; i++)
        {
            for(int j = -1; j<= 1; j++)
            {
                int nc1 = c1+i, nc2 = c2+j;
                if(nc1>=0 and nc1<n and nc2>=0 and nc2<n)
                {
                    ans = max(ans, dfs(g,m,n,r+1, nc1,nc2));
                }
            }
        }
        int ch = (c1==c2? g[r][c1]: g[r][c1]+g[r][c2]);
        return dp[r][c1][c2] = ans + ch;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1, sizeof(dp));
        return dfs(grid,m,n,0,0,n-1);
    }
};