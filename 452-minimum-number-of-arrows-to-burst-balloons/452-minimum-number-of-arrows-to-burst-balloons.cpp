class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), cmp);
        int ans = 0 ;
        int curr = 0;
        for(int i = 0; i<a.size(); i++)
        {
            if(a[i][0] <= a[curr][1])
                continue;
            ans++;
            curr = i;
        }
        return ans+1;
    }
};