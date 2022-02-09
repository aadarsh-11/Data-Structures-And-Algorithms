class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n = days.size();
        int dp[401]={0};
        int curr = 0;
        bool flag = 0;
        for(int i = 1 ; i < 401;i++)
        {
            if(!flag and days[curr] == i)
            {
                dp[i] = dp[i-1]+cost[0];
                curr++;
            }
            else
            {
                dp[i] = dp[i-1];
            }
            if(i>=7)
            {
                dp[i] = min(dp[i], dp[i-7] + cost[1]);
            }

            if(i>=30)
            {
                dp[i] = min(dp[i], dp[i-30] + cost[2]);
            }
            if(curr == n) 
            {
                curr = i;
                flag = 1;
            }
        }
        return dp[400];
    }
};