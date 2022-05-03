class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r and nums[l] == nums2[l]) l++;
        while(l<r and nums[r] == nums2[r]) r--;
        
        return r == l? 0 : r-l+1;
    }
};