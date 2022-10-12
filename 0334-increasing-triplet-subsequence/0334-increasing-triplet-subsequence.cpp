class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x=-1,y = -1, z = -1;
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(x == -1)
            {
                x = i;
                continue;
            }
            if(y == -1)
            {
                if(nums[i] > nums[x])
                {
                    y = i;
                    continue;
                }
                x = i;
                continue;
            }
            if(nums[i] < nums[y])
            {
                if(nums[i] > nums[x])
                {
                    y = i;
                    continue;
                }
                x = i;
                continue;
            }
            if(nums[i] > nums[y]) return 1;
        }
        return 0;
    }
};