class Solution {
public:
    int f(vector<pair<int,int>> &a, int z, int o, int i,vector<vector<vector<int>>> & dp)
    {
        if(i<0) return 0;
        if(dp[i][z][o] != -1) return dp[i][z][o];
        if(a[i].first <= z and a[i].second <= o)
        {
            return dp[i][z][o] = max(f(a,z-a[i].first,o-a[i].second, i-1,dp)+1, f(a,z,o,i-1,dp));
        }
        return dp[i][z][o] = f(a,z,o,i-1,dp);
    }
    
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
        vector<vector<vector<int>>> dp(a.size(), vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return f(a,m,n,a.size()-1,dp);
    }
};