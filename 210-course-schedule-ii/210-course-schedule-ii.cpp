class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> deg(n);
        for(auto i: pre)
        {
            graph[i[1]].push_back(i[0]);
            deg[i[0]]++;
        }
        queue<int> q;
        
        for(auto &i: deg)
        {
            int ind = &i-&deg[0];
            if(i == 0)
            {
                q.push(ind);
                n--;
            }
        }
        vector<int> topo;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            for(auto v: graph[curr])
            {
                deg[v]--;
                if(deg[v] == 0)
                {
                    q.push(v);
                    n--;
                }
            }
        }
        if(n)
            topo.clear();
        
        return topo;
    }
};