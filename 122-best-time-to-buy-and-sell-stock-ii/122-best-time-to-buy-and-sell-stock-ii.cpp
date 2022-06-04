class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int ans = 0;
        for(auto i: prices)
        {
            mn = min(mn, i);
            
            if(i > mn)
            {
                ans += i- mn;
                mn = i;                
            }
        }
        return ans;
    }
};