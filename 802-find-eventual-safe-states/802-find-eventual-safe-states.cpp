class Solution {
public:
    
    int dfs(vector<vector<int>>& g, vector<int>& safe,vector<int>& vis, int u)
    {
        vis[u] = 1;
        for(auto v: g[u])
        {
            if(vis[v])
            {
                vis[u] = 0;
                return safe[u] = 0;
            }
            if(safe[v] == -1)
            {
                safe[v] = dfs(g,safe,vis,v);
            }
            if(safe[v] == 0)
            {
                vis[u] = 0;
                return safe[u] = 0;
            }
        }
        vis[u] = 0;
        return safe[u] = 1;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> safe(n,-1), ans,vis(n);
        for(int i = 0 ; i <n ; i++)
        {
            if(safe[i] == -1)
            {
                safe[i] = dfs(g, safe, vis, i);
            }
            if(safe[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};