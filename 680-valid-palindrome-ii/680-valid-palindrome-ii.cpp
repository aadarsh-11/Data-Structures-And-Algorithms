class Solution {
public:
    bool validPalindrome(string s, bool flag = 0) {
        int l = 0;
        int r = s.size()-1;

        while(l<=r)
        {
            if(s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                if(flag) return 0;
                return validPalindrome(s.substr(l+1,r-l),1) or validPalindrome(s.substr(l,r-l),1);
            }
        }
        return 1;
    }
};