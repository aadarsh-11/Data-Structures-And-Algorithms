class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for( int j = i+1 ; j < n ; j++)
            {
                int x = nums[i] + nums[j];
                int k = lower_bound(nums.begin()+j,nums.end(), x) - nums.begin()-1;
                if(k > j)
                    ans += k-j;
            }
        }
        return ans;
    }
};