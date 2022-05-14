class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g(n,vector<int>(n,1e8));
        for(auto i: times)
        {
            g[i[0]-1][i[1]-1] = i[2];
        }
        for(int i = 0 ; i < n ; i++)
        {
            g[i][i] = 0;
        }
        for(int k = 0 ; k < n ; k++)
        {
            for(int i = 0 ; i <n; i++)
            {
                for(int j = 0 ; j < n; j++)
                {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(g[k-1][i] == 1e8) return -1;
            ans = max(ans, g[k-1][i]);
        }
        return ans;
    }
};