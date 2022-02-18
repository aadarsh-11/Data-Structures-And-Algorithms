class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<int> st;
        
        for(int i = 0 ; i< num.size(); i++)
        {
            int x = num[i]-'0';
            while(k and !st.empty() and st.top() > x)
            {
                st.pop();
                k--;
            }
            if(st.empty() and x == 0) continue;
            st.push(x);
        }
        while(!st.empty() and k)
        {
            st.pop();
            k--;
        }
        if(k or st.empty()) return "0";
         
        while(!st.empty())
        {
            ans = (char)(st.top()+'0') + ans;
            st.pop();
        }
        return ans;
    }
};