class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                }
                else
                {
                    grid[i][j] = INT_MAX;
                }
            }
        }
        if(q.empty() or q.size() == n*m) return -1;
        
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1}, {-1,0}};
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                auto x = q.front();
                q.pop();
                for(auto d: dir)
                {
                    int i = x[0] + d[0];
                    int j = x[1] + d[1];
                    
                    if(i<0 or i>= n or j<0 or j>=m or grid[i][j] <= grid[x[0]][x[1]] + 1)
                        continue;
                    grid[i][j] = grid[x[0]][x[1]] + 1;
                    q.push({i,j});
                }
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                ans = max(ans, grid[i][j]);
            }
        }
        return ans-1;
    }
};