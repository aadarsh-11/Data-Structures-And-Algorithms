class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        int ans = 0;
        int l = 0;
        map<char,int> mp;
        
        for(auto i: s)
        {
            if(mp[i] > 0)
            {
                while(s[l] != i)
                {
                    mp[s[l]]--;
                    l++;
                    ans--;
                }
                l++;
            }
            else
            {
                ans++;
                mp[i]++;
                mx = max(mx,ans);
            }
        }
        return mx;
    }
};