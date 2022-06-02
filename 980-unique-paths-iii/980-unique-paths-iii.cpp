class Solution {
public:
    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    void dfs(int x, int y,vector<vector<int>>& grid, vector<vector<bool>>& vis, int obs, int &res)
    {
        if(grid[x][y] == 2)
        {
            if(obs == 0) res++;
            return;
        }
        vis[x][y] = 1;
        obs--;
        
        for(auto d: dir)
        {
            int i = x+d.first;
            int j = y+d.second;
            
            if(i<0 or i>=grid.size() or j < 0 or j >= grid[0].size() or vis[i][j] or grid[i][j] == -1)
                continue;
            
            dfs(i,j,grid,vis,obs,res);
        }
        vis[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int obs = 0;
        int x = 0, y = 0;
        
        for(int i = 0 ; i< n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
                else if(grid[i][j] == 0) obs++;
            }   
        }
        
        int res = 0;
        
        dfs(x,y,grid,vis,obs+1, res);
        
        return res;
    }
};