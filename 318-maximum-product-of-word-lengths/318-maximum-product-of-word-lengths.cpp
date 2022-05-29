class Solution {
public:
    int maxProduct(vector<string>& words) {
        map<int,int> mp;
        for(auto word : words)
        {
            int mask = 0;
            for(auto w: word)
            {
                mask |= 1 << (w-'a');
            }
            mp[mask] = max(mp[mask],(int) word.size());
        }
        int ans = 0;
        for(auto x : mp)
        {
            for(auto y : mp)
            {
                if(x.first & y.first) continue;
                ans = max(ans, x.second*y.second);
            }
        }
        return ans;
    }
};