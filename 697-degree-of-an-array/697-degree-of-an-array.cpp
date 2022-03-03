class Solution {
public:
    int findShortestSubArray(vector<int>& a) {
        unordered_map<int,int> cnt;
        unordered_map<int,pair<int,int>> mp;
        int maxf = 0;
        int ans = a.size();
        
        for(int i = 0 ; i< a.size() ; i++)
        {
            if(cnt.find(a[i]) == cnt.end())
            {
                mp[a[i]] = {i,i};
            }
            else
            {
                mp[a[i]].second = i;
            }
            cnt[a[i]]++;
            maxf = max(maxf, cnt[a[i]]);
        }
        
        
        for(auto i: mp)
        {
            if(cnt[i.first] == maxf)
            {
                ans = min(ans, i.second.second - i.second.first+1);
            }
        }
        
        return ans;
    }
};