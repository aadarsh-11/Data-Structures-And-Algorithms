class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // int n = nums.size();
        vector<int> v;
        for(int i = 0; i <n ; i++)
        {
            int ps = 0;
            for(int j = i; j<n; j++)
            {
                ps += nums[j];
                v.push_back(ps);
            }
        }
        sort(v.begin(), v.end());
        return accumulate(v.begin() + left-1, v.begin() + right, 0ll) % (long long)(1e9+7);
    }
};