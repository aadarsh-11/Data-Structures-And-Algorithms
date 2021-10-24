class Solution {
public:
    int findMin(vector<int>& a,int l = 0, int r = -1 ){
        int n = a.size();
        // int l = 0;
        if(r == -1)
            r = n-1;
        // int r = n-1;
        while(l< r)
        {
            if(a[l] < a[r]) return a[l];
            if(r-l == 1) return min(a[l], a[r]);
            int mid = (l+r)/2;
            if(a[mid] < a[r]) r = mid;
            else if(a[mid] == a[r] and a[mid ] == a[l]) 
                return min(findMin(a,l,mid), findMin(a, mid+1,r));
            else if(a[l] > a[mid])
                r = mid;
            else
                l = mid;
        }
        return min(a[l], a[r]);
    }
};