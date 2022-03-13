class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &i: s)
        {
            if(i == '(' or i == '{' or i == '[')
                st.push(i);
            else
            {
                if(st.empty()) return false;
                if(i - st.top() == 1 or i - st.top() == 2) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};