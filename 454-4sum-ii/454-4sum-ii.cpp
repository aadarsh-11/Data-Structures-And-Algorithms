#define ll long long int

class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d){
        map<ll,ll> mp,mp2;
        for(auto i:a)
        {
            mp[-i]++;
        }
        for(auto i: b)
        {
            for(auto x:mp)
            {
                mp2[x.first-i] += x.second;
            }
        }
        mp.clear();
        mp = mp2;
        mp2.clear();
        for(auto i: c)
        {
            for(auto x:mp)
            {
                mp2[x.first-i] += x.second;
            }
        }
        mp.clear();
        mp = mp2;
        mp2.clear();
        
        int ans = 0;
        
        for(auto i: d)
        {
            if(mp[i]) 
            {
                ans += mp[i];
            }
        }
        return ans;
    }
};