class Solution {
public:
    int countOrders(int n) {
        vector<long long int> dp(n+1);
        dp[1] = 1;
        long long int mod = 1000000007;
        for(int i =2; i<=n; i++)
        {
            long long int x = (i-1)*2+1;
            dp[i] = (dp[i-1]*((x*(x+1))/2))%mod;
        }
        return (int)(dp[n]%(mod));
    }
};