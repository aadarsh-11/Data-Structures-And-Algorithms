class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0 ;
        unordered_map<int,int> mp;
        int sum = 0;
        int l = 0, r = 0;
        mp[nums[l]]++;
        ans = nums[l];
        sum = nums[l];
        r = 1;
        while(r < nums.size())
        {
            if(mp[nums[r]])
            {
                while(nums[l] != nums[r])
                {
                    sum -= nums[l];
                    mp[nums[l++]]--;
                }
                l++;
            }
            else
            {
                mp[nums[r]]++;
                sum += nums[r];
            }
            r++;
            ans = max(ans, sum);
        }
        return ans;
    }
};