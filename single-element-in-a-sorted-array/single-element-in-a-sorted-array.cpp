class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int r = a.size()-1;
        int l = 0;
        
        while(r>l)
        {
            int mid = (l+r)/2;
            if(mid%2)
            {
                if(a[mid] == a[mid-1])
                {
                    l = mid+1;
                }
                else
                {
                    r= mid;
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
        return a[l];
    }
};