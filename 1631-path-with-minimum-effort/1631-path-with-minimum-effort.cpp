class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& g) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int n = g.size();
        int m = g[0].size();
        pq.push({0,0,0});
        
        vector<vector<int>> par(n,vector<int>(m,INT_MAX));
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        int ans = INT_MAX;
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            
            int x = curr[1];
            int y = curr[2];
            int w = curr[0];
            
            if(x == n-1 and y == m-1)
            {
                ans = w;
                break;
            }
            
            for(auto d:dir)
            {
                int nx = x+d[0];
                int ny = y+d[1];
                
                if(nx>=n or nx<0 or ny>=m or ny<0 or par[nx][ny] <= max(w,abs(g[nx][ny]-g[x][y]))) continue;
                pq.push({max(w,abs(g[nx][ny]-g[x][y])),nx,ny});
                par[nx][ny] = max(w,abs(g[nx][ny]-g[x][y]));
            }
        }
        return ans;
    }
};