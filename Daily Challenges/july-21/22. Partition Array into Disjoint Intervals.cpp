class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int n = a.size();
        vector<int> mx(n),mn(n);
        int x = a[0];
        for(int i = 0 ; i < n; i++)
        {
            if(x< a[i])
            {
                x = a[i];
            }
            mx[i] = x;
        }
        x = a[n-1];
        for(int i = n-1 ; i >= 0; i--)
        {
            if(x > a[i])
            {
                x = a[i];
            }
            mn[i] = x;
        }
        for(int i = 0 ; i < n ; i ++)
        {
            cout<<i<<" "<<mn[i]<<" "<<mx[i]<<endl;
        }
        for(int i = 0 ; i < n-1; i++)
        {
            if(mx[i] <= mn[i+1])
                return i+1;
        }
        return n-1;
    }
};
