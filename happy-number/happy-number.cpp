class Solution {
public:
    int getn(int x)
    {
        int ts = 0;
        while(x>0)
        {
            int n = x%10;
            x = x/10;
            ts += n*n;
        }
        return ts;
    }
    bool isHappy(int n) {
        set<int> s;
        while(n != 1 and s.find(n) == s.end())
        {
            s.insert(n);
            n = getn(n);
        }
        return n == 1;
    }
};