class Solution {
public:
    int minJumps(vector<int>& a) {
        map<int, vector<int>> mp;
        int n = a.size();
        for(int i = 0 ; i < n; i++)
        {
            mp[a[i]].push_back(i);
        }
        
        queue<int> q;
        vector<int> vis(n,0);
        vis[0] = 1;
        q.push(0);
        int ans = 0;
        while(!q.empty())
        {
            int s = q.size();
            for(int i = 0 ; i < s; i++)
            {
                int u = q.front();
                q.pop();
                if(u == (n-1))
                {
                    return ans;
                }
                
                vector<int> &next = mp[a[u]];
                next.push_back(u-1);
                next.push_back(u+1);
                for(auto v: next)
                {
                    if(v>0 and v<n and !vis[v])
                    {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
                next.clear();
            }
            ans++;    
        }
        return ans;
    }
};