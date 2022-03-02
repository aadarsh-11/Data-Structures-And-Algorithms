class Solution {
public:
    bool isSubsequence(string t, string s) {
        if(t.size() == 0) return true;
        if(s.size() < t.size()) return false;
        int si = 0;
        int ti = 0;
        while(si<s.size())
        {
            if(s[si] == t[ti])
            {
                s[si] == t[ti];
                si++; ti++;
            }
            else
            {
                si++;
            }
            if(ti == t.size()) return true;
        }
        return false;
    }
};