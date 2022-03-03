class Solution {
public:
    int countBinarySubstrings(string s) {
        int pc = 0, cc = 1;
        int ans = 0;
        for(int i = 1 ; i < s.size(); i++)
        {
            if(s[i] != s[i-1])
            {
                ans += min(pc,cc);
                pc = cc;
                cc = 1;
            }
            else
            {
                cc++;
            }
        }
        ans += min(cc,pc);
        return ans;
    }
};