class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int right = 0;
        int left = 0;
        
        for(auto i: nums)
        {
            left = max(left, i);
            right += i;
        }
        
        //binary search the answer;
        int ans = right;
        
        while(left < right)
        {
            int mid = left + (right-left)/2;
            
            int currsum = 0;
            int splits = 1;
            for(int i = 0 ; i < nums.size(); i++)
            {
                currsum += nums[i];
                if(currsum > mid)
                {
                    splits++;
                    currsum = nums[i];
                }
            }
            if(splits <= m)
            {
                ans = min(ans, mid);
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};