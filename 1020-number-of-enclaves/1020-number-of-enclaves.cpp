class Solution {
public:
    int dfs(vector<vector<int>>&g, int x,int y)
    {
        int n = g.size();
        int m = g[0].size();
        if(x >=n or x <0 or y>=m or y<0 ) return -1;
        if(g[x][y] == 0) return 0;
        g[x][y] = 0;
        int a,b,c,d;
        a = dfs(g,x+1,y);
        b = dfs(g,x-1,y);
        c = dfs(g,x,y+1);
        d = dfs(g,x,y-1);
        if(a == -1 or b == -1 or c == -1 or d == -1)
        {
            return -1;
        }
        return a+b+c+d+1;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0 ; i< grid.size(); i++)
        {
            for(int j = 0 ; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    int res = dfs(grid,i,j);
                    if(res == -1) continue;
                    ans += res;
                }
            }
        }
        return ans;
    }
};