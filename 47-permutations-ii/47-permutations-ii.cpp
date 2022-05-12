class Solution {
public:
    set<vector<int>> ans;
    void f(vector<int>&nums, int ind)
    {
        if(ind == nums.size()-1)
        {
            ans.insert(nums);
            return;
        }
        for(int i = ind+1;i<nums.size(); i++)
        {
            if(nums[i] != nums[ind])
            {
                swap(nums[i], nums[ind]);
                f(nums, ind+1);
                swap(nums[i], nums[ind]);
            }
        }
        f(nums, ind+1);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        f(nums, 0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};