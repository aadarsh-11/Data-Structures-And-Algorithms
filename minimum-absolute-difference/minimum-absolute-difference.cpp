class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        sort(a.begin(), a.end());
        int mn = INT_MAX;
        vector<vector<int>> ans;
        for(int i = 0; i < a.size()-1; i++)
        {
            mn = min(mn, a[i+1]-a[i]);
        }
        
        for(int i = 0; i < a.size()-1; i++)
        {
            if((a[i+1]-a[i]) == mn)
            {
                ans.push_back({a[i],a[i+1]});
            }
        }
        return ans;
    }
};