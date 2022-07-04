class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        bool inc = 0;
        int frwd = 1, back = 1;
        int n = nums.size();
        int curr = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            if(inc)
            {
                if(nums[i] > curr)
                {
                    frwd++;
                    inc = 1-inc;
                }
                curr = nums[i];
            }
            else
            {
                if(nums[i] < curr)
                {
                    frwd++;
                    inc = 1 - inc;
                }
                curr = nums[i];
            }
        }
        
        inc = 1;
        curr = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(inc)
            {
                if(nums[i] > curr)
                {
                    back++;
                    inc = 1-inc;
                }
                curr = nums[i];
            }
            else
            {
                if(nums[i] < curr)
                {
                    back++;
                    inc = 1 - inc;
                }
                curr = nums[i];
            }
        }
        
        return max(frwd, back);
    }
};