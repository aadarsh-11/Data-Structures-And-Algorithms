class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(),a.end());
        set<vector<int>> ans;
        vector<int>x;
        ans.insert(x);
        for(int i = 0 ; i < a.size(); i++)
        {
            int n = ans.size();
            set<vector<int>> hehe = ans;
            for(auto j: hehe)
            {
                vector<int> tmp = j;
                tmp.push_back(a[i]);
                ans.insert(tmp);
            }
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
