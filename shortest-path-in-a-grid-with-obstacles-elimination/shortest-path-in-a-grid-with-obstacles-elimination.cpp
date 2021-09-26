class Solution {
public:
    int shortestPath(vector<vector<int>>& g, int k) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>> vis(n, vector<int>(m,-1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        while(!q.empty())
        {
            auto i = q.front();
            q.pop();
            int x = i[0], y = i[1];
            if(x>=n or x<0 or y >=m or y<0)
                continue;
            if(g[x][y] == 1)
            {
                if(i[3] > 0) 
                    i[3]--;
                else
                    continue;
            }
            if(x == n-1 and y == m-1)
                return i[2];
            if(vis[x][y] != -1 and vis[x][y] >= i[3])
            {
                continue;
            }
            vis[x][y] = i[3];
            
            q.push({x+1, y, i[2]+1, i[3]});
            q.push({x, y+1, i[2]+1, i[3]});
            q.push({x-1, y, i[2]+1, i[3]});
            q.push({x, y-1, i[2]+1, i[3]});
        }
        return -1;
    }
};