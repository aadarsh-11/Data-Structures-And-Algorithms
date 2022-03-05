class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        unordered_map<int,int> mp;
        int mx = a[0];
        
        for(auto i: a)
        {
            mp[i]++;
            mx = max(mx,i);
        }
        vector<int> dp(mx+2);
        
        dp[1] = mp[1];
        dp[2] = max(mp[2]*2, mp[1]);
        
        for(int i = 3; i < mx+1; i++)
        {
            dp[i] = max(dp[i-1], mp[i]*i + dp[i-2]);
        }
        return max(dp[mx], dp[mx-1]);
    }
};