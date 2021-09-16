class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int cans = 1;
        int ans = 1;
        int n = a.size();
        for(int i = 1 ; i< n ; i++)
        {
            if(i < n-1 and a[i] > a[i-1] and a[i] > a[i+1])
            {
                cans +=2;
                ans = max(ans,cans);
                i++;
            }
            else if(a[i] > a[i-1])
            {
                cans ++;
                ans = max(ans,cans);
                cans = 1;
                
            }
            else
            {
                cans = 1;
            }
        }
        cans = 1;
        for(int i = 1 ; i< n ; i++)
        {
            if(i < n-1 and a[i] < a[i-1] and a[i] < a[i+1])
            {
                cans +=2;
                ans = max(ans,cans);
            i++;
            }
            else if(a[i] < a[i-1])
            {
                cans ++;
                ans = max(ans,cans);
                cans = 1;
            }
            else
            {
                cans = 1;
            }
        }
        return ans;
    }
};