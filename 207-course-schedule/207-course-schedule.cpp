class Solution {
public:
    
    bool dfs(int i, vector<vector<int>> &g, vector<int> &vis, vector<int> &dvis)
    {
        vis[i]++;
        dvis[i]++;
        for(auto v: g[i])
        {
            if(dvis[v]) return false;
            if(!vis[v])
            {
                bool ret = dfs(v,g,vis,dvis);
                if(ret == false)
                    return false;
            }
        }
        dvis[i] --;
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n);
        for(auto i: pre)
        {
            g[i[0]].push_back(i[1]);
        }
        
        vector<int> vis(n,0), dvis(n,0);
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                if(!dfs(i,g,vis,dvis))
                    return false;
            }
        }
        return true;
    }
};