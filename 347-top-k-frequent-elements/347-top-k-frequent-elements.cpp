class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int>> vp;
        for(auto i : mp)
        {
            vp.push_back({i.second,i.first});
        }
        sort(vp.rbegin(), vp.rend());
        
        int j = 0;
        for(auto i : vp)
        {
            if(j == k) break;
            ans[j++] = i.second;
        }
        return ans;
    }
};