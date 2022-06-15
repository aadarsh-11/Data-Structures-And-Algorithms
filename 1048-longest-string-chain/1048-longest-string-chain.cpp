class Solution {
public:
    bool compare(string &s1, string &s2)
    {
        // cout<<s1<<" "<<s2<<endl;
        if(s1.size() != s2.size() + 1) return 0;
        int i = 0, j = 0;
        while(i<s1.size() and j < s2.size())
        {
            if(s1[i] != s2[j])
            {
                i++;
                continue;
            }
            i++, j++;
        }
        return j == s2.size();
    }
    
    int rec(vector<string> &words, int pre, int curr, vector<vector<int>> &dp)
    {
        // cout<<pre<<" "<<curr<<endl;
        if(curr == words.size()) return 0;
        if(pre == -1) return max(1 + rec(words,curr,curr+1,dp), rec(words, pre, curr+1,dp));
        
        if(dp[pre][curr] != -1) return dp[pre][curr];
        
        if(compare(words[curr], words[pre]))
        {
            // cout<<curr<<" "<<pre<<endl;
            return dp[pre][curr] = max(1 + rec(words,curr,curr+1,dp), rec(words, pre, curr+1,dp));
        }
        
        // cout<<pre<<" - "<<curr<<endl;
        return dp[pre][curr] = rec(words, pre, curr+1, dp);
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string &s, string &t) {
            return s.size() < t.size();
        });
        
        int n = words.size();
        // for(auto i: words) cout<<i<<endl;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return rec(words, -1,0, dp);
    }
};