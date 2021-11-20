class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size();
        int m = a[0].size();
        int r = n-1, l = 0;
        int row = -1;
        while(r>l)
        {
            int mid = (l+r)/2;
            if(target == a[mid][0])
            {
                return true;
            }
            if(target > a[mid][0])
            {
                l = mid+1;
            }
            else if(target < a[mid][0])
            {
                r = mid-1;
            }
        }
        if(l < n and a[l][0] > target)
        {
            l--;
            if(l<0) return false;
        }
        
        row = l;
        l = 0;
        r = m-1;
        
        while(r>=l)
        {
            int mid = (l+r)/2;
            if(target == a[row][mid])
            {
                return true;
            }
            if(target > a[row][mid])
            {
                l = mid+1;
            }
            else if(target < a[row][mid])
            {
                r = mid-1;
            }
        }
        return false;
    }
};