class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> ans;
        int cnt = 0;
        int li = 0;
        for(int i = 0 ; i< n; i++)
        {
            cnt++;
            if(s[i] == ' ')
            {
                string t = s.substr(li, cnt-1);
                if(t != "")
                ans.push(t);
                cnt = 0;
                li = i+1;
            }
        }
        if(li<n)
        {
           ans.push(s.substr(li, cnt));
        }
        string x = "";
        while(!ans.empty())
        {
            if(x == "")
            {
                x += ans.top();
            }
            else
            {
                x += " " + ans.top();
            }
            ans.pop();
        }
        return x;
    }
};