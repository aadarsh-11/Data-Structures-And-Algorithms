class Solution {
public:
    
    void dfs(vector<vector<char>>&g, int x,int y, vector<vector<int >>& vis)
    {
        int n = g.size();
        int m = g[0].size();
        if(x >=n or x <0 or y>=m or y<0 or vis[x][y] or g[x][y] == '0') return;
        vis[x][y] = 1;
        dfs(g,x+1,y,vis);
        dfs(g,x-1,y,vis);
        dfs(g,x,y+1,vis);
        dfs(g,x,y-1,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));
        int ans = 0;
        
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j< grid[i].size(); j++)
            {
                if(grid[i][j] == '1' and !vis[i][j])
                {
                    ans++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return ans;
    }
};