class Solution {
public:
    void dfs(int x, int y, vector<vector<int>> &a, vector<vector<int>>&vis, int pre)
    {
        if(x<0 or x >= a.size() or y<0 or y >= a[0].size() or vis[x][y] == 1 or pre > a[x][y]) return;
        vis[x][y] = 1;
        dfs(x+1,y,a,vis,a[x][y]);
        dfs(x,y+1,a,vis,a[x][y]);
        dfs(x-1,y,a,vis,a[x][y]);
        dfs(x,y-1,a,vis,a[x][y]);      
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> po(n,vector<int>(m,0)),ao(n, vector<int> (m,0));
        for(int i = 0 ; i< n; i++)
        {
            dfs(i,0,a,po,-1);
        }
        for(int i = 1 ; i< m; i++)
        {
            dfs(0,i,a,po,-1);
        }
        for(int i = 0 ; i< n; i++)
        {
            dfs(i,m-1,a,ao,-1);
        }
        for(int i = 0 ; i< m-1; i++)
        {
            dfs(n-1,i,a,ao,-1);
        }
        
        vector<vector<int>> ans;
        for(int i = 0 ; i <n; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(po[i][j] and ao[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};