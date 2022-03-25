class Solution {
public:
    static bool cmp(vector<int> &a, vector<int>&b)
    {
        return a[0]-a[1] < b[0]-b[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(), cmp);
        int n = costs.size();
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            if(i<n/2)
            {
                ans += costs[i][0];
            }
            else
            {
                ans += costs[i][1];
            }
        }
        return ans;
    }
};