class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool flag = 0;
        int n = s.size();
        int i = 0;
        while(i < n and s[i] == ' ') i++;
        if(s[i] == '-') flag=1;
        else if(s[i] == '+')flag = 0;
        else if(s[i]-'0' < 0 or s[i]-'0' > 9) return ans;
        else i--;
        
        i++;
        while(s[i]-'0' >= 0 and s[i]-'0' <= 9)
        {
            ans *= 10;
            ans += s[i]-'0';
            if(ans > (long long)INT_MAX*100ll) break;
            i++;
        }
        
        if(flag) ans = -ans;
        
        if(ans > INT_MAX) ans = INT_MAX;
        if(ans<INT_MIN) ans = INT_MIN;
        
        return ans;
    }
};