class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int n = 0;
        int r = n%k;
        while(n<=k)
        {
            r = r*10 + 1;
            n++;
            if(r%k == 0) return n;
            else
            {
                r = r%k;
            }
        }
        return -1;
    }
};