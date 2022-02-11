class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp,mp2;
        for(auto c: s1)
        {
            mp[c]++;
        }
        int n = s1.size();
        int m = s2.size();
        if(m < n) return 0;
        for(int i = 0 ; i<n-1; i++)
        {
            mp2[s2[i]]++;
        }
        for(int i = n-1; i<m; i++)
        {
            mp2[s2[i]]++;
            if(mp2 == mp)
                return 1;
            mp2[s2[i-n+1]]--;
            if(mp2[s2[i-n+1]] == 0)
            {
                mp2.erase(s2[i-n+1]);
            }
        }
        return 0;
    }
};