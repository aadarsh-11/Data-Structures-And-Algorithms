class Solution {
public:
    int countOrders(int n) {
        long dp;
        dp = 1;
        int mod = 1000000007;
        for(int i =2; i<=n; i++)
        {
            int x = (i-1)*2+1;
            dp *= ((x*(x+1))/2 );
            dp %= mod;
        }
        return (int)dp;
    }
};