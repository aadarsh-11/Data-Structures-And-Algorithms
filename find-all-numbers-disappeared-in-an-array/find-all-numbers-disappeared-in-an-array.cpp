class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i= 1; i<=n; i++)
        {
            mp[i]++;
        }
        for(auto i: nums)
        {
            mp.erase(i);
        }
        vector<int>ans;
        for(auto i: mp)
        {
            ans.push_back(i.first);
        }
        return ans;
    }
};