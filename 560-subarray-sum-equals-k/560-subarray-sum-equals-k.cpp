class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        int ans = (a[0]==k);
        map<int,int> mp;
        mp[0] = 1;
        mp[a[0]]++;
        for(int i = 1; i<n; i++)
        {
            a[i] += a[i-1];
            ans += mp[a[i]-k];
            mp[a[i]]++;
        }
        return ans;
    }
};