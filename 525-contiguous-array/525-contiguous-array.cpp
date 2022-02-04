class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        int zero=0, one = 0;
        int ans = 0;
        mp[0] = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                zero++;
            else
                one++;
            if(mp.find(one-zero)!=mp.end())
                ans = max(ans,i+1-mp[one-zero]);
            else
                mp[one-zero] = i+1;
        }
        // ans = max(ans,mp[0]);
        return ans;
    }
};