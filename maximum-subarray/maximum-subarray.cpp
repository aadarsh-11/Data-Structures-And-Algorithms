class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int mx = a[0];
        int cs = 0;
        int r = 0;
        while(r< a.size())
        {
            cs += a[r];
            mx = max(mx,cs);
            if(cs<0)
            {
                cs = 0;
            }
            r++;
        }
        return mx;
    }
};