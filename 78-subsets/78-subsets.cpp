class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums, int i = 0) {
        int n = pow(2,nums.size());
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i ++)
        {
            vector<int> v;
            for(int x = 0; x<nums.size(); x++)
            {
                if(i>>x & 1) v.push_back(nums[x]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};