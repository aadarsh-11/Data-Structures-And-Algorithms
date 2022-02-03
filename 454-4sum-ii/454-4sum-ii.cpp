#define ll long long int

class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d){
        map<ll,ll> mp,mp2,mp3;
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
            mp3[i]++;
        }
        mp2.clear();
        mp2 = mp3;
        mp3.clear();
        
        int ans = 0;
        
        for(auto i: d)
        {
            for(auto x:mp2)
            {
                mp3[x.first+i] += x.second;
            }
        }
        
        for(auto i: mp3)
        {
            if(mp[i.first]) ans += i.second*mp[i.first];
        }
        
        return ans;
    }
};