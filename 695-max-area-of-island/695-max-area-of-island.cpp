class Solution {
public:
    int dfs(vector<vector<int>>&g, int x,int y,int &area)
    {
        int n = g.size();
        int m = g[0].size();
        if(x >=n or x <0 or y>=m or y<0 or g[x][y] == 0) return area;
        g[x][y] = 0;
        area++;
        dfs(g,x+1,y,area);
        dfs(g,x-1,y,area);
        dfs(g,x,y+1,area);
        dfs(g,x,y-1,area);
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;        
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j< grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = 0;
                    ans = max(ans,dfs(grid,i,j,area));
                }
            }
        }
        return ans;
    }
};