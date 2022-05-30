class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN and divisor == -1) return INT_MAX;
        long ans = 0;
        
        bool sign = (dividend > 0) ^ (divisor > 0);
        
        long dvd = abs(dividend);
        long div = abs(divisor);
        while(dvd >= div)
        {
            int x = 0;
            while(dvd >= div << x)
            {
                x++;
            }
            x--;
            ans += 1<<x;
            dvd -= div<<x;
        }
        if(sign) ans = -ans;
        return (int)ans;
    }
};