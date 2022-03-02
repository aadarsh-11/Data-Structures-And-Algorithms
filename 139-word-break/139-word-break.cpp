class Solution {
public:
    bool inserted = 0;
    set<string> st;
    map<string, bool> dp;
    bool wordBreak(string s, vector<string>& dict) {
        if(s == "") return true;
        if(dp.find(s) != dp.end()) return dp[s];
        
        string str = "";
        if(!inserted)
        {
            inserted = 1;
            for(auto i: dict)
            {
                st.insert(i);
            }
        }
        for(int i = 0 ; i< s.size(); i++)
        {
            str += s[i];
            if(st.find(str) != st.end())
            {
                string rem = s.substr(i+1,s.size() - i - 1);
                if(wordBreak(rem, dict)) return dp[rem] = true;
            }
        }
        return dp[s] = false;
    }
};