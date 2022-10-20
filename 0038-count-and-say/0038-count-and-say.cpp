class Solution {
public:
    string say(string s)
    {
        string res = "";
        int digit = s[0]-'0';
        int cnt = 0;
        for(auto c: s)
        {
            if(digit == c-'0') cnt++;
            else
            {
                res += to_string(cnt) + to_string(digit);
                digit = c-'0';
                cnt = 1;
            }
        }
        if(cnt) 
                res += to_string(cnt) + to_string(digit);
        
        return res;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        return say(countAndSay(n-1));
    }
};