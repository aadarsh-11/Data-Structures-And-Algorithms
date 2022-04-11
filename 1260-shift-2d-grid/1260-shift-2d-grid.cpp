class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int rs = (k/m) % n;
        k = k%m;
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i = 0 ; i< n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                ans[rs][k++] = grid[i][j];
                k%=m;
                if(k == 0)
                {
                    rs++;
                    rs%=n;
                }
            }
        }
        return ans;
    }
};