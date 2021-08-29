class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        ans.push_back(a[0]);
        for(int i = 0 ; i < a.size() ; i++)
        {
            if(a[i][0] <= ans.back()[1])
            {
                ans.back()[1] = max(a[i][1], ans.back()[1]);
            }
            else
            {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};