class Solution {
public:
    map<int,int> dp;
    int coinChange(vector<int>& a, int x) {
        if(x == 0) return 0;
        if(dp[x] != 0) return dp[x];
        sort(a.rbegin(), a.rend());
        int ans = 0;
        int n = a.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(a[i]<= x)
            {
                int b = coinChange(a,x-a[i]);
                if(b == -1) 
                {
                    dp[x-a[i]] = -1;
                    continue;
                }
                else
                {
                    dp[x-a[i]] =b;
                }
                if(!ans)
                {
                    ans = 1+b;
                }
                else
                {
                    ans = min(ans,1+b);
                }
            }
        }
        dp[x] = ans;
        if(ans == 0) dp[x] = -1;
        return dp[x];
    }
};