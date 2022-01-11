class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> vis(n,0), col(n,-1);
        queue<int> q;
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {                
                q.push(i);
                col[i] = 0;
            
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    vis[u]++;
                    for(auto v: g[u])
                    {
                        if(col[u] == col[v]) return false;
                        if(!vis[v])
                        {
                            q.push(v);
                            col[v] = 1-col[u];
                        }
                    }
                }
            }
        }
        return true;
    }
};