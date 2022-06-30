class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int mid = nums[n/2];
        
        for(auto i: nums)
            ans += abs(i-mid);
        
        return ans;
    }
};