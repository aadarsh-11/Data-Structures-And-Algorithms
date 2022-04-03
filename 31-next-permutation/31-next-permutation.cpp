class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i>0 and nums[i] <=  nums[i-1])
            i--;
        
        i--;
        int j = i+1;
        int mx = j;
        if(i != -1)
        {
            
        while(j<n)
        {
            if(nums[j] > nums[i])
            {
                if(nums[j] < nums[mx])
                {
                    mx = j;
                }
            }
            if(nums[j] < nums[i]) break;
            j++;
        }
        swap(nums[i], nums[mx]);
        }
        sort(nums.begin()+i+1, nums.end());
    }
};