class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if(n == 1) return "";
        for(int i = 0 ; i < n; i ++)
        {
            if(s[i] != 'a')
            {
                if(n%2 and i == n/2) continue;
                s[i] = 'a';
                return s;
            }
        }
        s[n-1] = 'b';
        return s;
    }
};