class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> res(n, vector<int>(n));
        int k = n*n;
        int i = 0 , j = 0;
        int x = 0;
        for(int v = 1; v<= k; v++)
        {
            res[i][j] = v;
            i += dir[x][0];
            j += dir[x][1];
            if(i<0 or i>=n or j<0 or j>=n or res[i][j] != 0)
            {                
                i -= dir[x][0];
                j -= dir[x][1];
                
                x = (x+1)%4;
                
                i += dir[x][0];
                j += dir[x][1];
            }
        }
        return res;
    }
};