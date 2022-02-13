class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if(n > m)
        {
            return findMedianSortedArrays(b,a);
        }
        int left = 0;
        int right = n;
        
        while(left <= right)
        {
            int cut1 = left + (right-left)/2;
            int cut2 = (n+m+1)/2 - cut1;
            
            double l1 = cut1 == 0 ? INT_MIN : a[cut1-1];
            double l2 = cut2 == 0 ? INT_MIN : b[cut2-1];
            double r1 = cut1 == n ? INT_MAX : a[cut1];
            double r2 = cut2 == m ? INT_MAX : b[cut2];
            
            if(l1 <= r2 and l2<= r1)
            {
                if((n+m)%2)
                {
                    return max(l1,l2);
                }
                else
                {
                    return (max(l1,l2) + min(r1,r2))/2;
                }
            }
            else
            {
                if(l1 > r2)
                {
                    right = cut1-1;
                }
                else
                {
                    left = cut1+1;
                }
            }
        }
        return 0;
    }
};