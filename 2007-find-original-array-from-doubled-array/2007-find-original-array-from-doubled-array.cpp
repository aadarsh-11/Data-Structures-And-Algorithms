class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        map<int,int> mp;
        for(auto i: changed) mp[i]++;
        
        vector<int> ans;
        for(auto i: changed)
        {
            if(mp[i] == 0)continue;
            mp[i]--;
            if(mp[2*i] == 0) return vector<int>();
            mp[2*i]--;
            ans.push_back(i);
        }
        return ans;
    }
};