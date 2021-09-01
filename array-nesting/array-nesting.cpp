class Solution {
public:
    int arrayNesting(vector<int>& a) {
        vector<int> dp(a.size(),0);
        int n = a.size();
        int ans = 1;
        for(int i = 0 ; i < n ; i++)
        {
            if(!dp[i])
            {
                int start = a[i];
                int cnt = 0;
                do {
                    
                    start = a[start];
                    if(dp[start]) break;
                    cnt++;
                    dp[start] = 1;
                } while(start != a[i]);
                ans = max(ans, cnt);
            }
        }
        return  ans;
    }
};