class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3] = {0};
        for(auto i: nums)
            a[i]++;
        
        int j = 0;
        for(int i = 0 ; i< nums.size(); i++)
        {
            if(a[j]) nums[i] = j;
            else
            {
                j++;
                i--;
                continue;
            }
            a[j]--;
        }
    }
};