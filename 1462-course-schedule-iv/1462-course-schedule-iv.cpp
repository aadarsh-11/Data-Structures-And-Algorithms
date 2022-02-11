class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<vector<int>> adj(n,vector<int>(n,0));
        for(auto i: p)
        {
            adj[i[0]][i[1]] = 1;
        }
        for(int k = 0 ; k < n;  k++)
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    adj[i][j] = adj[i][j] or (adj[i][k] and adj[k][j]);
                }
            }
        }
        vector<bool> ans(q.size());
        for(int i = 0 ; i < q.size(); i++)
        {
            ans[i] = (adj[q[i][0]][q[i][1]] == 1);
        }
        return ans;
    }
};