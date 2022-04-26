class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> added(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans = 0;
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            if(added[curr.second]) continue;
            added[curr.second] = 1;
            ans += curr.first;
            
            for(int i = 0 ; i < n; i++)
            {
                if(added[i] == 1) continue;
                pq.push({abs(points[i][0]-points[curr.second][0]) + abs(points[i][1]-points[curr.second][1]), i});
            }
        }
        return ans;
    }
};