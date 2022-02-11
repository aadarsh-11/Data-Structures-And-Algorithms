class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<set<int>> g(n);
        for(auto i: edges)
        {
            g[i[0]].insert(i[1]);
            g[i[1]].insert(i[0]);
        }
        vector<int> l;
        for(int i =0; i < n ; i++)
        {
            if(g[i].size() == 1)
                l.push_back(i);
        }
        int rem = n;
        while(rem>2)
        {
            vector<int> newL;
            for(auto leaf:l)
            {
                int par = *g[leaf].begin();
                g[par].erase(g[par].find(leaf));
                if(g[par].size() == 1)
                {
                    newL.push_back(par);
                }
                rem--;
            }
            l = newL;            
        }
        if(l.size() == 0) l.push_back(0);
        return l;
    }
};