class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<int>> dp;
    
    void dfs(string s, int start, vector<string>&curr)
    {
        if(start >= s.size())
        {
            ans.push_back(curr);
        }
        for(int end = start; end<s.size(); end++)
        {
            if(s[start] == s[end] and ((start >= end-2 ) or dp[start+1][end-1]))
            {
                dp[start][end] = true;
                curr.push_back(s.substr(start,end-start+1));
                dfs(s,end+1, curr);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<int>> dp2(s.size(), vector<int> (s.size(),0));
        dp = dp2;
        dfs(s, 0, curr);
        return ans;
    }
};