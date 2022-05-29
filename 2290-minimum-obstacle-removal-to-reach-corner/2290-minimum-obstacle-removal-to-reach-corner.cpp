class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        
        q.push({0,{0,0}});
        dist[0][0] = 0;
        int cnt = 0;
        
        while(!q.empty())
        {
            int d = q.top().first;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();
            
            if(d > dist[i][j]) continue;
            
            for(auto x:dir)
            {
                int ni = i+x[0];
                int nj = j+x[1];
                
                if(ni<0 or ni>= n or nj <0 or nj >= m or dist[ni][nj] <= grid[ni][nj] + dist[i][j]) 
                    continue;
                
                dist[ni][nj] = grid[ni][nj] + dist[i][j];
                q.push({dist[ni][nj],{ni,nj}});
                
                if(ni == n-1 and nj == m-1) return dist[n-1][m-1];
            }
        }
        return dist[n-1][m-1];
    }
};