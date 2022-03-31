class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 1;
        int sum = nums[0];
        int ans = INT_MAX;
        while(r<nums.size())
        {
            if(sum>=target)
            {
                ans = min(ans, r-l);
                sum -= nums[l++];
            }
            else
            {
                sum+=nums[r++];
            }
        }
        
        while(sum>=target)
        {
            ans = min(ans, r-l);
            sum -= nums[l++];
        }
        return (ans == INT_MAX ? 0 : ans);
    }
};