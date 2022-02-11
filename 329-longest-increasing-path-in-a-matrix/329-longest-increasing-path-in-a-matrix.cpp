class Solution {
public:
    
    bool isval(int i, int j, vector<vector<int>>&g)
    {
        if(i>=0 and i<g.size() and j>=0 and j<g[0].size()) return true;
        return false;
    }
    
    int dfs(vector<vector<int>>&dp, vector<vector<int>>&g, int i, int j)
    {
        if(dp[i][j]!= -1) return dp[i][j];
        vector<pair<int,int>> dir = {{1,0},{0,1}, {-1,0}, {0,-1}};
        int val = 0;
        for(auto d:dir)
        {
            int x = i+d.first;
            int y = j+d.second;
            if(isval(x,y,g) and g[x][y] > g[i][j])
            {
                val = max(val,dfs(dp,g,x,y));
            }
        }
        return dp[i][j] = val+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& g) {
        vector<vector<int>> dp(g.size(), vector<int>(g[0].size(),-1));
        int ans = 1;
        for(int i = 0 ; i < g.size(); i++)
        {
            for(int j = 0 ; j < g[0].size(); j++)
            {
                ans = max(ans , dfs(dp,g,i,j));
            }
        }
        return ans;
    }
};