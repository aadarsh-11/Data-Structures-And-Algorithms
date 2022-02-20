class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int curr = n+m-1;
        m--;
        n--;
        while(m>=0 and n>=0)
        {
            if(a[m] <= b[n])
                a[curr--]=b[n--];
            else
            {
                a[curr--]=a[m--];
            }
        }
        while(m>=0)
        {
            a[curr--] =a[m--];
        }
        while(n>=0)
        {
            a[curr--] =b[n--];
        }
    }
};