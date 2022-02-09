class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto i: nums)
        {
            mp[i]++;
        }
        int ans = 0;
        for(auto &i: mp)
        {
            if(k == 0)
            {
                if(i.second > 1) ans++;
                continue;
            }
            auto it = mp.find(i.first+k);
            if(it != mp.end() and it->second != 0)
                ans ++;
            
            it = mp.find(i.first-k);
            if(it != mp.end() and it->second !=0)
                ans ++;
            
            i.second = 0;
        }
        return ans;
    }
};