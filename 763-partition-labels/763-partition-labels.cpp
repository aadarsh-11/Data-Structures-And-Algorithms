class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26,0);
        for(int i = 0 ; i < s.size(); i++)
        {
            mp[s[i]-'a'] = i;
        }
        vector<int> ans;
        int cs = 0;
        int cl = mp[s[0]-'a'];
        for(int i = 0 ; i<s.size(); i++)
        {
            if(mp[s[i]-'a'] > cl)
                cl = mp[s[i]-'a'];
            if(i == cl)
            {
                ans.push_back(cl-cs+1);
                cs = i+1;
                cl = i+1;
            }
        }
        return ans;
    }
};