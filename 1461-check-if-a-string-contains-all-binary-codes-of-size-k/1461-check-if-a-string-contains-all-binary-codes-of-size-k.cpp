class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>=s.size()) return false;
        
        int num = 0;
        int mask = 0;
        
        for(int i = 0 ; i< k; i++)
        {
            num = num<<1 | (s[i]-'0');
            mask = mask<<1 | 1;
        }
        unordered_map<int,bool> mp;
        mp[num] = 1;
        
        for(int i = k ; i< s.size(); i++)
        {
            num = num << 1 | (s[i]-'0');
            num &= mask;
            mp[num] = 1;
        }
        
        return mp.size() == (1<<k);
    }
};