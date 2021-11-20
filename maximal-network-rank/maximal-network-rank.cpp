class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> v(n), mat(n, vector<int>(n,0));
        int ans= 0;
        for(auto i: roads)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
            mat[i[0]][i[1]] = 1;
            mat[i[1]][i[0]] = 1;
        }
        
        for(int i = 0 ; i<n; i++)
        {
            for(int j = i+1 ; j<n; j++)
            {
                ans = max(ans,int( v[i].size()+v[j].size()-(mat[i][j])));
            }
        }
        return ans;
    }
};