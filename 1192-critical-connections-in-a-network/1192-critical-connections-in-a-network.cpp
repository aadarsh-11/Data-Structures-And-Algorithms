class Solution {
public:
    vector<vector<int>> ans;
    int timer;
    void dfs(int curr, int par, vector<vector<int>>& g, vector<int>& inTime, vector<int>& low, vector<int>& vis)
    {
        vis[curr]= 1;
        inTime[curr] = low[curr] = timer++;
        for(auto v: g[curr])
        {
            if(v == par) continue;
            
            if(!vis[v])
            {
                dfs(v,curr,g,inTime,low,vis);
                if(low[v] > inTime[curr])
                {
                    ans.push_back({curr,v});
                }
            }
            low[curr] = min(low[curr], low[v]);            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for(auto e: connections)
        {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        timer = 0;
        vector<int> vis(n,0), inTime(n,0), low(n,0);
        for(int i = 0 ; i<n; i++)
        {
            if(!vis[i])
                dfs(i,-1,g,inTime, low, vis);
        }
        return ans;
    }
};