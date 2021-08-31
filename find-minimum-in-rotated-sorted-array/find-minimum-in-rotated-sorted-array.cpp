class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0 ; 
        int r = n-1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(mid == l and a[l] > a[r])
            {
                l = r;
                continue;
            }
            if(mid == l)
            {
                r = l;
                continue;
            }
            if(a[l] > a[mid])
            {
                r = mid;
                continue;
            }
            else if(a[mid] < a[r])
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return a[l];
    }
};