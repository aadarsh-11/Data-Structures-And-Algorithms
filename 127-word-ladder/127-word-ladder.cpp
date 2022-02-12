class Solution {
public:
    int ladderLength(string b, string e, vector<string>& dict) {
        int ans =2;
        queue<string> q;
        int n = dict.size();
        map<string, bool>mp;
        bool found = 0;
        for(auto i: dict)
        {
            mp[i] = 1;
            if(i == e) found = 1;
        }
        if(!found) return 0;
        
        q.push(b);
        mp[b] = 0;
        while(!q.empty())
        {
            n = q.size();
            while(n--)
            {
                auto curr = q.front();
                q.pop();
                for(int i = 0 ; i < curr.size(); i++)
                {
                    char x = curr[i];
                    for(char c = 'a'; c<='z'; c++)
                    {
                        if(curr[i] == c) continue;
                        curr[i] = c;
                        if(curr == e) return ans;
                        if(mp[curr])
                        {
                            mp[curr] = 0;
                            q.push(curr);
                        }
                    }
                    curr[i] = x;
                }
            }
            ans++;
        }
        return 0;
    }
};