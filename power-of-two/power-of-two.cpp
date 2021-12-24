class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return 0;
        long long int ans = 0;
        while(n>0)
        {
            ans += n&1;
            n>>=1;
        }
        return ans == 1;
    }
};