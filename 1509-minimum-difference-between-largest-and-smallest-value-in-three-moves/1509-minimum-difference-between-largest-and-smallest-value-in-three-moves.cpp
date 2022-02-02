class Solution {
public:
    int minDifference(vector<int>& a) {
        int n = a.size();
        if(n<=4) return 0;
        sort(a.begin(),a.end());
        int ans = a.back()-a[0];
        ans = min({ans, a[n-4]-a[0],a[n-3]-a[1],a[n-2]-a[2],a[n-1]-a[3]});
        return ans;
    }
};