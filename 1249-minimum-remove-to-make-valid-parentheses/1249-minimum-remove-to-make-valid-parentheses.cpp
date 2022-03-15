class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int cnt = 0;
        string ans = "";
        for(auto i: s)
        {
            if(i == '(')
            {
                open++;
            }
            if(i == ')')
            {
                if(open>0)
                {
                    open--;
                    cnt++;
                }
            }
        }
        open = 0;
        for(auto i: s)
        {
            if(i == '(' and cnt)
            {
                cnt--;
                open++;
                ans += i;
            }
            else if(i == ')' and open)
            {
                open--;
                ans+= i;
            }
            else if(i != ')' and i != '(')
            {
                ans += i;
            }
        }
        return ans;
    }
};