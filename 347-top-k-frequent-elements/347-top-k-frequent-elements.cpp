class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        map<int,int> mp;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto i : mp)
        {
            pq.push({i.second,i.first});
            if(pq.size() > k) pq.pop();
        }
        int j = 0;
        while(!pq.empty())
        {
            ans[j++] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};