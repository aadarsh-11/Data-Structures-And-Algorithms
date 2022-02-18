class Solution {
public:
    bool searchMatrix(vector<vector<int>>& b, int target) {
        int n = b.size();
        int m = b[0].size();
        if(target < b[0][0] or target > b[n-1][m-1]) return false;
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(b[mid][0] == target) return true;
            if(b[mid][0] > target)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        int row = r;
        l = 0, r = m-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(b[row][mid] == target) return true;
            if(b[row][mid] > target)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return false;
    }
};