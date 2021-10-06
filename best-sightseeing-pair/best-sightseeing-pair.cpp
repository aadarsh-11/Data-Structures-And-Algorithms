class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int n = a.size();
        vector<int> b(n);
        for(int i = 0 ; i< n; i ++)
        {
            b[i] = a[i] - i;
            a[i] += i;
            if(i>0)
            a[i] = max(a[i],a[i-1]);
        }
        int ans = INT_MIN;
        for(int i = n-2; i>=0; i--)
        {
            b[i] = max(b[i], b[i+1]);
            ans = max(ans, a[i]+b[i+1]);
        }
        return ans;
        
    }
};