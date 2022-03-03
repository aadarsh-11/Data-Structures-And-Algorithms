class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int ans = 0, n = a.size();
        if(n<3) return 0;
        
        int pd = a[1]-a[0];
        int cnt = 0;
        for(int i = 1 ; i < n-1; i++)
        {
            a[i+1]-a[i] == pd ? cnt++ : cnt = 0;
            pd = a[i+1]-a[i];
            ans += cnt;
        }
        return ans;
    }
};