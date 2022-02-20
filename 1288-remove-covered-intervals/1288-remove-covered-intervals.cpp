class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if(a[0] == b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& a) {
        int ans = 1;
        sort(a.begin(),a.end(),cmp);
        int ind = 0;
        for(int i = 1 ; i< a.size() ; i++)
        {
            if(a[ind][1] >= a[i][1])
            {
                continue;
            }
            else
            {
                ind = i;
                ans++;
            }
        }
        return ans;
    }
};