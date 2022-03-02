class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xn = 0;
        int xc = 0;
        for(int i = 0 ; i< nums.size() ; i++)
        {
            xc = (xc^nums[i]);
            xn = (xn^(i+1));
        }
        return xc^xn;
    }
};