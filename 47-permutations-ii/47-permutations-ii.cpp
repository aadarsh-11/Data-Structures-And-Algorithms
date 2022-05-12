class Solution {
public:
    vector<vector<int>> ans;
    void f(unordered_map<int,int> &mp,vector<int>&curr, int n)
    {
        if(curr.size() == n) ans.push_back(curr);
        for(auto &i: mp)
            if(i.second > 0)
            {
                i.second--;
                curr.push_back(i.first);
                f(mp,curr,n);
                curr.pop_back();
                i.second++;
            }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i: nums)
            mp[i]++;
        vector<int> curr;
        f(mp,curr, nums.size());
        return ans;
    }
};