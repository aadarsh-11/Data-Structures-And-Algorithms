class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& bef) {
        for(int i = 0 ; i < n; i++)
        {
            if(group[i] == -1)
                group[i] = m++;
        }
        vector<int> gid(m), deg(n);
        vector<vector<int>> after(n);
        map<int, vector<int>> gmem;
        for(int i = 0 ; i < n ; i++)
        {
            for(auto x: bef[i])
            {
                after[x].push_back(i);
                deg[i]++;
            if(group[i] != group[x])
                gid[group[i]]++;
            }
            gmem[group[i]].push_back(i);
        }
        queue<int> q;
        for(int i = 0 ; i < m; i++)
        {
            if(gid[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        
        // cout<<"stage 1 clear"<<q.size();
        
        while(!q.empty())
        {
            int cg = q.front();
            q.pop();
            // cout<<cg<<" - group\n";
            auto items = gmem[cg];
            queue<int> iq;
            for(auto i: items)
            {
                if(deg[i] == 0)
                {
                    iq.push(i);
                }
            }
            while(!iq.empty())
            {
                int ci = iq.front();
                iq.pop();
                // cout<<ci<<"-curr item"<<endl;
                ans.push_back(ci);
                for(auto gm: after[ci])
                {
                    // cout<<gm<<endl;
                    if(--deg[gm] == 0 and group[gm] == group[ci])
                    {
                        // cout<<"same grp"<<gm<<endl;
                        iq.push(gm);
                    }
                    if(group[gm] != group[ci])
                    {
                        if(--gid[group[gm]] == 0)
                            q.push(group[gm]);
                    }
                }
            }
        }
        // for(auto i: ans)
        // {
        //     cout<<i<<" ";
        // }
        if(ans.size() != n) ans.clear();
        return ans;
    }
};