class Solution {
public:
    int maxProfit(vector<int>& a) {
        int mx = 0;
        int sy = a[0];
        for(int i = 0 ; i< a.size() ; i ++)
        {
            mx = max(mx, a[i] - sy);
            if(a[i]<sy)
                sy = a[i];
        }
        return mx;
    }
};