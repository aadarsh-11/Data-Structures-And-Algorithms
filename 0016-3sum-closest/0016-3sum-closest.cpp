class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size(); i++)
        {
            int t = target - nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l<r)
            {
                int sum = nums[l] + nums[r] + nums[i];
                if(diff >= abs(sum-target))
                {
                    ans = sum;
                    diff = abs(sum-target);
                }
                if(nums[l] + nums[r] > t)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return ans;
    }
};