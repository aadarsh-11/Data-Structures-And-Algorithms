class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = (n>0);
        int cmax = 1;
        
        map<long long int,int> mp;
        
        for(auto i:nums)
            mp[i]++;
        
        long long int lm = INT_MIN;
        
        for(auto i: mp)
        {
            if(i.first - lm == 1ll)
            {
                cmax++;
                ans = max(ans,cmax);
            }
            else
            {
                cmax = 1;
            }
            lm = i.first;
        }
        
        return ans;
    }
};