class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        map<string,vector<string>> ma;
        for(int i = 0 ; i <n; i++)
        {
            string x = s[i];
            sort(x.begin(), x.end());
            ma[x].push_back(s[i]);
        }
        vector<vector<string>> ans;
        // vector<string> a;
        for(auto i: ma)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};