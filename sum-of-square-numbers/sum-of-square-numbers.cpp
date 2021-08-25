class Solution {
public:
    bool isq(long long int x)
    {
        long long int z = sqrt(x);
        return (z*z == x);
    }
    bool judgeSquareSum(int c) {
        for(long long int i = 0; i*i <=c; i++)
        {
            long long int x = (long long int)c-i*i;
            // cout<<x<<endl;;
            if(isq(x)) return true;
        }
        return false;
    }
};