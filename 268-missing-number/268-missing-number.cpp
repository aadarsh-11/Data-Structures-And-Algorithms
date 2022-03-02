class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xc = 0;
        for(int i = 0 ; i< nums.size() ; i++)
        {
            xc ^= nums[i];
            xc ^= (i+1);
        }
        return xc;
    }
};