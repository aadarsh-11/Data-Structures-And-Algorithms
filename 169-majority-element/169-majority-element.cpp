class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me;
        int mec = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            if(mec == 0)
            {
                me = nums[i];   
            }
            mec += (me == nums[i]? 1:-1);
        }
        return me;
    }
};