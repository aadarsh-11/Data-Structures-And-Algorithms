class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int sum = 0;
        mp[0] = 0;
        for(int i = 0 ; i< n ; i++)
        {
            sum += nums[i];
            mp[sum] = i+1;
        }
        
        sum = 0;
        int ans = -1;
        
        if(mp.find(x) != mp.end()) ans = mp[x];
        
        for(int i = n-1; i >= 0 ; i--)
        {
            sum += nums[i];
            int req = x - sum;
            if(req < 0)
            {
                break;
            }
            if(mp.find(req) != mp.end())
            {
                if(ans == -1)
                    ans = mp[req] + n - i;
                else
                    ans = min(ans, mp[req] + n - i);
            }
        }
        return ans > n ? -1 : ans;
    }
};