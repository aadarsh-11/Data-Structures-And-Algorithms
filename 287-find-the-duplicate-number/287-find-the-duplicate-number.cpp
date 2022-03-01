class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        while(true)
        {
            if(nums[i] < 0)
            {
                ans = i;
                break;
            }
            nums[i] = -nums[i];
            i = -nums[i];
        }
        i = 0;
        while(nums[i] < 0)
        {
            nums[i] = - nums[i];
            i = nums[i];
        }
        return ans;
    }
};