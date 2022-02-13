// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    
    bool isval(int x, int y, int n)
    {
        if(x<=n and y<=n and x>0 and y>0) return true;
        return false;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&start,vector<int>&end,int n)
	{
	   // cout<<start[0]<<" "<<start[1]<<endl;
	   // cout<<end[0]<<" "<<end[1]<<endl;
	    if(start == end) return 0;
	    vector<vector<int>> dir = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
	    vector<vector<int>> vis(n+1,vector<int> (n+1,0));
	    queue<vector<int>> q;
	    q.push(start);
	    vis[start[0]][start[1]] = 1;
	    int ans = 0;
	    while(!q.empty())
	    {
	        int s = q.size();
	        
	        while(s--)
	        {
    	        auto curr = q.front();
    	        q.pop();
	            for(auto d: dir)
	            {
	                int x = curr[0] + d[0];
	                int y = curr[1] + d[1];
	                auto jump = curr;
	                jump[0] = x;
	                jump[1] = y;
	                
	                if(isval(x,y,n) and !vis[x][y])
	                {
	                    vis[x][y]=1;
	                    if(jump == end)
	                    {
	                        return ans+1;
	                    }
	                    else
	                    {
	                        q.push(jump);
	                    }
	                }
	            }
	        }
	            ans++;
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends