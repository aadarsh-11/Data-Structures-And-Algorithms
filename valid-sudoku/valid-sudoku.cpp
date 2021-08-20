class Solution {
public:
//     bool isvalnum(vector<vecto<char>> board, int x, int y)
//     {
//         int curr = board[x][y] - '0';
//         for(int i = 0 ; i < 9; i++)
//         {
//             if(i != x and board[i][y] == board[x][y])
                
//         }
//     }
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> mp;
        for(int i = 0 ; i < 9; i++)
        {            
            for(int j = 0 ; j < 9; j++)
            {
                if(board[i][j] == '.') continue;
                if(mp[board[i][j]]) return false;
                mp[board[i][j]]++;
            }
            mp.clear();
        }
        for(int i = 0 ; i < 9; i++)
        {            
            for(int j = 0 ; j < 9; j++)
            {
                if(board[j][i] == '.') continue;
                if(mp[board[j][i]]) return false;
                mp[board[j][i]]++;
            }
            mp.clear();
        }
        for(int i = 0; i < 9; i+=3)
        {
            for(int j = 0; j < 9; j+=3)
            {
                for(int x = 0 ; x< 3; x++)
                {
                    for(int y = 0 ; y<3; y++)
                    {
                        if(board[i+x][j+y] == '.') continue;
                        // cout<<i<<j<<x<<y<<endl;
                        if(mp[board[i+x][j+y]]) return false;
                        mp[board[i+x][j+y]]++;
                    }
                }                
                mp.clear();
            }
        }
        return true;
    }
};