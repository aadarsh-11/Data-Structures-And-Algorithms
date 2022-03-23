class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while(target > startValue)
        {
            if(target%2) 
            {
                target++;
                ans++;
            }
            target /= 2;
            ans++;
        }
        ans += startValue-target;
        return ans;
    }
};