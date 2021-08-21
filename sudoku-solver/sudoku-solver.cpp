class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& a, int x, int y) {
        for(int i = 0 ; i < 9; i++)
        {            
            if(i!=x and a[i][y] == a[x][y]) return false;
        }
        for(int i = 0 ; i < 9; i++)
        {            
            if(i!=y and a[x][i] == a[x][y]) return false;
        }
        int p = x/3;
        int q = y/3;
        p*=3;
        q*=3;
        for(int i = p; i < p+3; i++)
        {
            for(int j = q; j < q+3; j++)
            {
                if((i!=x or j!=y) and a[i][j] == a[x][y]) return false;
            }
        }
        return true;
    }
    
    bool solves(vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {                    
                    for(int x = 49 ; x< 58; x++)
                    {
                        board[i][j] = (char)x;
                        if(isValidSudoku(board,i,j))
                        {
                            if(solves(board))
                                break;
                            else
                                board[i][j] = '.';                                
                        }
                        else
                            board[i][j] = '.';
                    }
                    if(board[i][j] == '.') return false;
                    return true;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solves(board);
    }
};