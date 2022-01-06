class Solution {
public:
    vector<vector<int>> vis;
    void dfs(vector<vector<int>>& a, int i, int j, int val, int sc)
    {
        if(i<0 or i>= a.size() or j<0 or j>=a[0].size() or a[i][j] != sc or vis[i][j]) return;
        a[i][j] = val;
        vis[i][j] = 1;
        dfs(a,i+1,j,val,sc);
        dfs(a,i-1,j,val,sc);
        dfs(a,i,j+1,val,sc);
        dfs(a,i,j-1,val,sc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int newColor) {
        vector<vector<int>> vis2(a.size(),vector<int>(a[0].size(),0));
        vis = vis2;
        dfs(a,sr,sc,newColor, a[sr][sc]);
        return a;
    }
};