class Solution {
public:
    void rec(int n, int curr, vector<bool> &vis, int &ans)
    {
        if(curr> n)
        {
            ans++;
            return;
        }
        for(int i = 1; i<=n; i++)
        {
            if(!vis[i] and (curr%i == 0 or i%curr == 0))
            {
                vis[i] = 1;
                rec(n,curr+1,  vis, ans);
                vis[i] = 0;
            }
        }
        return;
    }
    
    int countArrangement(int n) {
        vector<bool> vis(n+1,0);
        int ans = 0;
        rec(n,1,vis, ans);
        return ans;
    }
};