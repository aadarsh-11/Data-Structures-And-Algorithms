class Solution {
public:
    int integerBreak(int n) {
        int ans = 1;
        if(n<4) return n-1;
        while(n>0)
        {
            if(n == 4) return ans*4;
            if(n<4) return ans*n;
            ans *= 3;
            n -= 3;
        }
        return ans;
    }
};