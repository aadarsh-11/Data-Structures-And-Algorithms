class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' or s[i] == '[' or s[i] == '{')
                st.push(s[i]);
            else
            {
                if(st.size() == 0) return 0;
                if(s[i] == ')' and st.top() == '(' or s[i] == ']' and st.top() == '[' or s[i] == '}' and st.top() == '{')
                {
                    st.pop();
                }
                else return 0;
            }
        }
        return st.size() == 0;
    }
};