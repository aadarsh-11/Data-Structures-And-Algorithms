class Solution {
public:
    int search(vector<int>& a, int t) {
        int n = a.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(a[mid]==t) return mid;
            if(a[l]<=a[mid])
            {
                if(a[l]<= t and a[mid]>=t)
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                if(a[r]>= t and a[mid]<=t)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};