class Solution {
public:
    set<vector<int>> ans;
    void rec(vector<int>& nums, int i, vector<int> &v)
    {
        if(i == nums.size()) return;
        v.push_back(nums[i]);
        ans.insert(v);
        rec(nums, i+1, v);
        
        v.pop_back();
        ans.insert(v);
        rec(nums, i+1, v);
    }
    vector<vector<int>> subsets(vector<int>& nums, int i = 0) {
        vector<int>v;
        rec(nums, 0, v);
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};