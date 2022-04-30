class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> g;
    unordered_map<string,bool> vis;
    double dfs(string u, string target,double val)
    {
        if(g.find(u) == g.end() or g.find(target) == g.end()) return -1;
        if(u == target) return val;
        vis[u] = 1;
        for(auto p: g[u])
        {
            auto v = p.first;
            auto w = p.second;
            if(!vis[v])
            {
                auto res = dfs(v,target,val*w);
                if(res != -1) return res;
            }
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // unordered_map<string,vector<pair<string,double>>> g;
        // unordered_map<string,bool> vis;
        
        int n = equations.size();
        for(int e = 0 ; e < n; e++)
        {
            string u = equations[e][0];
            string v = equations[e][1];
            double w1 = values[e];
            double w2 = (double)(1)/w1;
            g[u].push_back({v,w1});
            g[v].push_back({u,w2});
        }
        
        vector<double> ans(queries.size(),-1);
        for(int i = 0; i< queries.size(); i++)
        {
            ans[i] = dfs(queries[i][0],queries[i][1],1);
            vis.clear();
        }
        return ans;
    }
};