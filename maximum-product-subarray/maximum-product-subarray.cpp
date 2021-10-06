class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int ans =1;
        int fans = a[0];
        for(int i = 0 ; i < n ; i++)
        {
            ans *= a[i];
            fans = max(ans, fans);
            if(ans == 0) ans = 1;
        }
        ans = 1;
        for(int i = n-1 ; i >=0 ; i--)
        {
            ans *= a[i];
            fans = max(ans, fans);
            if(ans == 0) ans = 1;
        }
        return fans;
    }
};