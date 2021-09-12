class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return n;
        if(n<3) return 1;
        int a = 0,b=1,c=1;
        int ans = c;
        for(int i = 2 ; i< n; i++)
        {
            ans = a+b+c;
            a = b;
            b = c;
            c = ans;
        }
        return ans;
    }
};