class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        int mx = 0;
        for(auto i : nums)
        {
            mp[i]++;
            mx = max(mx,i);
        }
        int n = 10000+1;
        vector<int> dp(10000+1,0);
        dp[1] = mp[1];
        dp[2] = max(mp[2]*2,dp[1]); 
        for(int i = 3; i<n; i++)
        {
             dp[i] = max(mp[i]*i+dp[i-2],dp[i-1]);
        }
        return max(dp[n-1],dp[n-2]);
    }
};