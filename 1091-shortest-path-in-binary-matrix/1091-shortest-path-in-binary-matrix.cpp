#define f first
#define se second

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<pair<int,int>> dir = {{1,0},{0,1},{1,1},{-1,0},{0,-1},{-1,1},{1,-1},{-1,-1}};
        
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
        
        int cd = 1;
        dist[0][0] = 1;
        
        if(grid[0][0] == 0)
            q.push({0,0});
        
        while(!q.empty())
        {
            cd++;
            int s = q.size();
            while(s--)
            {
                auto cur = q.front();
                q.pop();
                for(auto d:dir)
                {
                    int nx = cur.f+d.f;
                    int ny = cur.se + d.se;
                    if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny] == 0 and dist[nx][ny] == -1)
                    {
                        dist[nx][ny] = cd;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];        
    }
};