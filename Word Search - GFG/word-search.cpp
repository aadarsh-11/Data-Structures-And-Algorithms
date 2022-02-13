// { Driver Code Starts
#include<bits/stdc++.h>
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
    bool bt(vector<vector<char>>& board, string word,vector<vector<int>> &vis, int x, int y, int wi)
    {
        if(wi == word.size()) return true;
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        for(auto d: dir)
        {
            int i = x+ d[0];
            int j = y+ d[1];
            if(isval(i,j,board) and board[i][j] == word[wi] and !vis[i][j])
            {
                vis[i][j] = 1;
                if(bt(board,word,vis,i,j,wi+1)) return true;
                vis[i][j] = 0;
            }
        }
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(bt(board, word, vis, i,j,0)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends