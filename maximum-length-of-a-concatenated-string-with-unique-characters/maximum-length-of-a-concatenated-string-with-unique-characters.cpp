class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        vector<string> res = {""};
        for(auto i: arr)
        {
            int n = res.size();
            for(int x = 0; x < n; x++)
            {
                string newres = res[x]+i;
                set<char> st(newres.begin(), newres.end());
                if(st.size() != newres.size())
                    continue;
                res.push_back(newres);
                ans= max(ans, (int)newres.size());
            }
        }
        return ans;
    }
};