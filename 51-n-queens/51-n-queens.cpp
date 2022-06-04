class Solution {
public:
    bool isval(vector<string> & curr, int i, int j)
    {
        for(int ii = 0; ii < i; ii++)
        {
            if(curr[ii][j] == 'Q') return 0;
        }
        
        int ii = i, jj = j;
        while(i > 0 and j > 0)
        {
            if(curr[--i][--j] == 'Q') return 0;
        }
        
        i = ii, j = jj;
        while(i>0 and j<curr.size()-1)
        {
            if(curr[--i][++j] == 'Q') return 0;
        }
        
        return 1;
    }
    
    void rec(int i, int j, vector<string> &curr, vector<vector<string>> &res, int n)
    {
        if(i == n)
        {
            res.push_back(curr);
            return;
        }
        for(int jj = j; jj < n ; jj++)
        {
            curr[i][jj] = 'Q';
            if(isval(curr, i, jj))
            {
                rec(i+1,0, curr, res,n);
            }
            curr[i][jj] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr (n,string(n,'.'));        
        
        rec(0,0,curr,res,n);
        
        return res;
    }
};