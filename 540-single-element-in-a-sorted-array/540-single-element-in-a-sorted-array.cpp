class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        int l =0;
        int r = n-1;
        if(n== 1) return a[0];
        if(a[0] != a[1]) return a[0];
        if(a[r] != a[r-1]) return a[r];
        int mid = 0;
        while(l<r)
        {
            mid = (l+r)/2;
            if(a[mid] != a[mid-1] and a[mid] != a[mid+1]) return a[mid];
            if(mid%2 == 1)
            {
                if(a[mid] == a[mid+1])
                {
                    r = mid;
                    continue;
                }
                else
                {
                    l = mid+1;
                    continue;
                }
            }
            else
            {
                if(a[mid] == a[mid+1])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid;
                }
            }
        }
        return a[mid];
    }
};