#define ll long long 
class Solution {
public:
    int getMaxLen(vector<int>& a) {
        int n = a.size();
        int l = 0;
        int al = 0;
        int ans = 1;
        for(int i = 0 ; i< n ; i++)
        {
            if(a[i] == 0)
            {
                l = 0;
                ans = 1;
                continue;
            }
            l++;
            ans *= a[i]/abs(a[i]);
            if(ans > 0) al = max(al,l);
        }
        ans = 1;
        l = 0;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if(a[i] == 0)
            {
                l = 0;
                ans = 1;
                continue;
            }
            l++;
            ans *= a[i]/abs(a[i]);
            if(ans > 0) al = max(al,l);
        }
        return al;
    }
};