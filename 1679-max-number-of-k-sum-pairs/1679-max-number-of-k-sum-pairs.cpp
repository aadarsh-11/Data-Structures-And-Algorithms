class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        int r = n-1;
        int ans = 0;
        sort(nums.begin(), nums.end());
        while(l<r)
        {
            if(nums[l] + nums[r] == k)
            {
                l++;
                r--;
                ans++;
            }
            else if(nums[l] + nums[r] < k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};