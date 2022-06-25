class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        
        bool change = 0;
        if(nums[0] > nums[1])
        {
            nums[0] = nums[1];
            change = 1;
        }
        for(int i = 1 ; i < nums.size()-1; i++)
        {
            if(nums[i] >= nums[i-1] and nums[i] <= nums[i+1]) continue;
            if(change) return 0;
            if(nums[i-1] <= nums[i+1])
                nums[i] = nums[i-1];
            else
                nums[i+1] =nums[i];
            change = 1;
        }
        if(change and nums[nums.size()-2] > nums[nums.size()-1]) return 0;
        return 1;
    }
};