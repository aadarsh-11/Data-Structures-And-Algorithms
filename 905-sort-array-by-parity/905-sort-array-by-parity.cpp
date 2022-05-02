class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ; int r = n-1;
        while(l<r)
        {
            if(nums[l]%2)
            {
                while(r>l and nums[r]%2) r--;
                if(l == r) break;
                swap(nums[l++],nums[r--]);
            }
            else l++;
        }
        return nums;
    }
};