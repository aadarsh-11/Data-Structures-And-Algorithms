class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto i: arr)
        {
            mp[i]++;
        }
        vector<int> v(mp.size());
        int i = 0;
        for(auto x: mp)
        {
            v[i++] = x.second;
        }
        
        sort(v.rbegin(),v.rend());
        int n = arr.size()/2;
        
        int ans = 0;
        i = 0;
        while(n > 0)
        {
            ans++;
            n-=v[i++];
        }
        
        return ans;
    }
};