class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        if(n> 1)
            dp[1] = max(nums[0],nums[1]);
        else
            return dp[0];
        for(int i = 2 ; i<n; i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return max(dp[n-1],dp[n-2]);
    }
};