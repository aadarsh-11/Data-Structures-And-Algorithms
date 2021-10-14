class Solution {
public:
    int numSquares(int n) {
        vector<int> a(n+1,INT_MAX), v;
        for(int i = 0; i*i <=n; i++)
        {
            a[i*i] = 1;
            if(i>0)
            v.push_back(i*i);
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j< v.size(); j++)
            {
                if(i-v[j] < 0) break;
                a[i] = min(a[i], a[i-v[j]]+1);
            }
        }
        return a[n];
    }
};