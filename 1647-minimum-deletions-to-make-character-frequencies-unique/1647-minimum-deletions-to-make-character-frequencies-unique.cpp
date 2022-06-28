class Solution {
public:
    int minDeletions(string s) {
        int a[26] = {0};
        for(auto i: s)
        {
            a[i-'a']++;
        }
        int ans = 0;
        
        sort(a,a+26);
        for(int i = 24; i>=0 and a[i]>0; i--)
        {
            if(a[i+1] == 0)
            {
                ans += a[i];
                a[i] = 0;
            }
            else if(a[i] >= a[i+1])
            {
                ans += a[i]-a[i+1]+1;
                a[i] = a[i+1]-1;
            }
        }
        
        return ans;
    }
};