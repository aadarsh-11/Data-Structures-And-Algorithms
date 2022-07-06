class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        int a = 0, b = 1;
        while(n>=2)
        {
            int c = a+b;
            a = b;
            b = c;
            n--;
        }
        return b;
    }
};