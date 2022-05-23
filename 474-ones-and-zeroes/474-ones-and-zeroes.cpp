class Solution {
public:    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> a;
        for(auto i: strs)
        {
            int x = i.size();
            int one = 0;
            for(auto c: i)
            {
                if(c == '1') one++;
            }
            a.push_back({x-one,one});
        }
        vector<vector<vector<int>>> dp(a.size(), vector<vector<int>>(m+1,vector<int>(n+1,0)));
        
        for(int i = 0 ; i< a.size(); i++)
        {
            for(int z = 0; z<=m; z++)
            {
                for(int o = 0; o<=n; o++)
                {
                    if(i == 0)
                    {
                        if(a[i].first <= z and a[i].second <= o)
                        {
                            dp[i][z][o] = 1;
                        }
                        continue;
                    }
                    if(a[i].first <= z and a[i].second <= o)
                        dp[i][z][o] = max(dp[i-1][z-a[i].first][o-a[i].second]+1, dp[i-1][z][o]);
                    else
                        dp[i][z][o] = dp[i-1][z][o];
                }
            }
        }
        return dp[a.size()-1][m][n];
    }
};