class Solution {
public:
    bool isval(vector<vector<int>> & curr, int i, int j)
    {
        for(int ii = 0; ii < i; ii++)
        {
            if(curr[ii][j]) return 0;
        }
        
        int ii = i, jj = j;
        while(i > 0 and j > 0)
        {
            if(curr[--i][--j]) return 0;
        }
        
        i = ii, j = jj;
        while(i>0 and j<curr.size()-1)
        {
            if(curr[--i][++j]) return 0;
        }
        
        return 1;
    }
    
    void rec(int i, int j, vector<vector<int>> &curr, int &res, int n)
    {
        if(i == n)
        {
            res++;
            return;
        }
        for(int jj = j; jj < n ; jj++)
        {
            curr[i][jj] = 1;
            if(isval(curr, i, jj))
            {
                rec(i+1,0, curr, res,n);
            }
            curr[i][jj] = 0;
        }
    }
    int totalNQueens(int n) {
        int res = 0;
        vector<vector<int>> curr (n,vector<int>(n));        
        
        rec(0,0,curr,res,n);
        
        return res;
    }
};