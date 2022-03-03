class Solution {
public:
    int countBinarySubstrings(string s) {
        int x = 0, y = 0;
        int ans = 0;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(i>0 and s[i] != s[i-1])
            {
                if(s[i] == '0')
                {
                    x = 0;
                }
                else
                {
                    y = 0;
                }
            }
            if(s[i] == '0')
            {
                x++;
                if(y)
                {
                    y--;
                    ans++;
                }
            }
            else
            {   
                y++;
                if(x)
                {
                    x--;
                    ans++;
                }
            }
        }
        return ans;
    }
};