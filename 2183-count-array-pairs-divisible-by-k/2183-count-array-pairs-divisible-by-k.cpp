class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long  ans = 0;
        unordered_map<int,int> gcds;
        for(auto i: nums)
        {
            int gcd = __gcd(i,k);
            for(auto [gcdj, n]: gcds)
            {
                if((long long)(gcdj)*(long long)(gcd) % k == 0)
                {
                    ans += n;
                }
            }
            gcds[gcd]++;
        }
        return ans;
    }
};