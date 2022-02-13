// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool isval(int x, int y, vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(x<n and y<m and x>=0 and y>=0) return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis, int x,int y)
    {
        vis[x][y] = 1;
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1},{1,1}, {1,-1}, {-1,1}, { -1,-1}};
        for(auto d: dir)
        {
            int i = x + d[0];
            int j = y + d[1];
            if(isval(i,j,grid) and grid[i][j] =='1' and !vis[i][j])
            {
                dfs(grid, vis, i,j);
            }
        }
        return ;
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int ans = 0;
        for(int i = 0 ; i < n; i ++)
        {
            for( int j = 0 ; j < m ; j++)
            {
                if(!vis[i][j] and grid[i][j] == '1')
                {
                    dfs(grid, vis, i,j);
                    ans++;
                // cout<<i<<" "<<j<<endl;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends