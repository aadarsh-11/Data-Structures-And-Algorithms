class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int lmax = 0;
        int rmax = 0;
        int ans = 0;
        while(l<=r)
        {
            if(height[l] >= lmax)
            {
                lmax = height[l];
                l++;
                continue;
            }
            if(height[r] >= rmax)
            {
                rmax = height[r];
                r--;
                continue;
            }
            if(lmax<=rmax)
            {
                ans += lmax - height[l++];
            }
            else
            {
                ans += rmax - height[r--];
            }
        }
        return ans;
    }
};