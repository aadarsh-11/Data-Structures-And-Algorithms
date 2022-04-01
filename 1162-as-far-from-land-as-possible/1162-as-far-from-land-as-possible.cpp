class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
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
        
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1}, {-1,0}};
        int ans = 0;
        
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            for(auto d: dir)
            {
                int i = x.first + d.first;
                int j = x.second + d.second;
                
                if(i<0 or i>= n or j<0 or j>=m or grid[i][j] <= grid[x.first][x.second] + 1)
                    continue;
                grid[i][j] = grid[x.first][x.second] + 1;
                ans = max(ans,grid[i][j]);
                q.push({i,j});
            }
        }

        return ans-1;
    }
};