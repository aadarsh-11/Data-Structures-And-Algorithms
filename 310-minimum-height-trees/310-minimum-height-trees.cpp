class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for(auto i: edges)
        {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
            deg[i[0]]++;
            deg[i[1]]++;
        }
        queue<int> q;
        for(int i =0; i < n ; i++)
        {
            if(deg[i] == 1)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.clear();
            int s = q.size();
            for(int i = 0 ; i < s; i++)
            {
                int leaf = q.front();
                q.pop();
                ans.push_back(leaf);
                for(auto par: g[leaf])
                {
                    if(--deg[par] == 1)
                    {
                        q.push(par);
                    }
                }
            }           
        }
        if(ans.size() == 0) ans.push_back(0);
        return ans;
    }
};