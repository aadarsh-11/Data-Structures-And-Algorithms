class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        priority_queue<pair<int,int>> pq;
        int n = a.size();
        for(int i = 0 ; i < n ; i++)
        {
            while(!pq.empty() && i - pq.top().second > k)
            {
                pq.pop();
            }
            if(!pq.empty() && i - pq.top().second <= k)
            {
                a[i] += pq.top().first;
                // cout<< pq.top().first<<" "<<a[i]<<endl;
            }
                pq.push({a[i],i});
        }
        // [1,-5,-20,4,-1,3,-6,-3]
        return a[n-1];
    }
};