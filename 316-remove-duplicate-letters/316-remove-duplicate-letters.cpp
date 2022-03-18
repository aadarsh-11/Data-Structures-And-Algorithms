class Solution {
public:
    string removeDuplicateLetters(string s) {
        string st="";
        vector<int> mp(26,0);
        vector<bool> vis(26,0);
        for(auto &i : s)
        {
            mp[i-'a']++;
        }
        for(auto &c:s)
        {
            int i = c -'a';
            if(vis[i]) 
            {
                mp[i]--;
                continue;
            }
            if(st.size() == 0)
            {
                st += c;
                mp[i]--;
                vis[i] = 1;
            }
            else
            {
                while(st.size() and st.back() >= c and mp[st.back()-'a'] > 0)
                {
                    vis[st.back()-'a']= 0;
                    st.pop_back();
                }
                st+= c;
                mp[i]--;
                vis[i]=1;
            }
        }
        return st;
    }
};