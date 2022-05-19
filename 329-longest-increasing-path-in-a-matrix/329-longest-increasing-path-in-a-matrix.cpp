class Solution {
public:
    int dfs(int i , int j, vector<vector<int>>&a, vector<vector<int>> &vis)
    {
        if(vis[i][j]) return vis[i][j];
        vector<vector<int>> dir = {{1,0},{-1,0}, {0,1}, {0,-1}};
        
        for(auto d: dir)
        {
            int ni = i+d[0];
            int nj = j+d[1];
            if(ni<0 or ni>=a.size() or nj<0 or nj >= a[0].size() or a[ni][nj] <= a[i][j]) continue;
            vis[i][j] = max(vis[i][j], dfs(ni,nj,a,vis));
        }
        vis[i][j]++;
        return vis[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        int ans = 1;
        
        vector<vector<int>> vis(n,vector<int>(m));
        
        for(int i = 0 ; i< n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                ans = max(ans, dfs(i,j,a,vis));
            }
        }
        return ans;
    }
};