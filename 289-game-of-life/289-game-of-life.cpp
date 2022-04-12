class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> dir = {{-1,-1}, {-1,1}, {-1,0},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                int oc = 0;
                for(auto d:dir)
                {
                    int ni = i+d[0];
                    int nj = j+d[1];
                    if(ni>=0 and ni<n and nj>=0 and nj<m and board[ni][nj] == 1) oc++; 
                }
                // cout<<i<<" "<<j<<" : "<<oc<<endl;
                if(board[i][j] == 0 and oc == 3) ans[i][j] = 1;
                else if(board[i][j] == 1 and (oc==2 or oc==3)) ans[i][j] = 1;
            }
        }
        board = ans;
    }
};