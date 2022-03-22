class Solution {
public:
    
    void dfs(vector<vector<char>>&g, int x,int y)
    {
        int n = g.size();
        int m = g[0].size();
        if(x >=n or x <0 or y>=m or y<0 or g[x][y] == '0') return;
        g[x][y] = '0';
        dfs(g,x+1,y);
        dfs(g,x-1,y);
        dfs(g,x,y+1);
        dfs(g,x,y-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j< grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};