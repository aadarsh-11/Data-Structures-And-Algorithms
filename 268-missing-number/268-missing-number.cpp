class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xc = (n*(n+1))/2;
        for(int i = 0 ; i< nums.size() ; i++)
        {
            xc -= nums[i];
        }
        return xc;
    }
};