class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        
        int mr = nums[0];
        int r = nums[0];
        
        int i = 0;
        int ans = 1;
        while(mr < n-1)
        {
            while(i<=r)
            {
                mr = max(mr, i+nums[i]);
                i++;
            }
            r = mr;
            ans++;
        }
        return ans;
    }
};