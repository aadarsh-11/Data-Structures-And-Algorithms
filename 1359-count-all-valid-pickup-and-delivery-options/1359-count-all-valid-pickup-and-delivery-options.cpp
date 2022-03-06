class Solution {
public:
    int countOrders(int n) {
        long long int dp;
        dp = 1;
        long long int mod = 1000000007;
        for(int i =2; i<=n; i++)
        {
            long long int x = (i-1)*2+1;
            dp = (dp * ((x*(x+1))/2)) %mod;
        }
        return (int)dp;
    }
};