class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v(n);
        int mod = 1e9+7;
        for(int i = 0 ; i < n ; i++)
        {
            v[i] = {efficiency[i], speed[i]};
        }
        sort(v.rbegin(), v.rend());
        long long sum = 0;
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0 ; i< k ; i++)
        {
            sum += v[i].second;
            pq.push(v[i].second);
            ans = max(ans, sum*v[i].first);
        }
        for(int i = k; i < n; i++)
        {
            pq.push(v[i].second);
            sum -= pq.top();
            pq.pop();
            sum += v[i].second;
            ans = max(ans, sum*v[i].first);
        }
        return ans%mod;
    }
};