class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> v(32,0);
        for(auto x: nums)
        {
            for(int i = 0 ; i< 32; i++)
            {
                v[i] += x&1;
                x>>=1;
            }
        }
        int ans = 0;
        for(auto i: v)
        {
            ans += i*(nums.size()-i);
        }
        return ans;
    }
};