class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, INT_MAX);
        k--;
        dist[k] = 0;
        vector<vector<pair<int,int>>> g(n);
        for(auto t : times)
        {
            g[t[0]-1].push_back({t[1]-1,t[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,k});
        
        while(!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto v: g[u])
            {
                if(dist[v.first] > d + v.second)
                {
                    dist[v.first] = d + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
        int ans = 0;
        for(auto i: dist)
        {
            ans = max(ans, i);
            if(i == INT_MAX) return -1;
        }
        
        return ans;
    }
};