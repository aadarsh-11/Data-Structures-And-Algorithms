class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) return nums[0] == target;
        if(nums[0] == target) return 1;
        int l = 1;
        int r = n-1;
        
        while(l<n and nums[l] == nums[l-1])
        {
            l++;
        }
        
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            if(nums[mid] <= nums[r])
            {
                if(target <= nums[r] and target >= nums[mid])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
            else
            {
                if(target<=nums[mid] and target >= nums[l])
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
        }
        return false;
    }
};