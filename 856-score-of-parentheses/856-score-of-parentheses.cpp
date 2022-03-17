class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(auto i:s)
        {
            if(i == '(')
                st.push(0);
            else
            {
                int curr = 0;
                if(st.top() == 0)
                {
                    st.pop();
                    curr = 1;
                }
                else
                {
                    curr = st.top()*2;
                    st.pop();
                    st.pop();
                }
                if(st.empty() or st.top() == 0)
                    st.push(curr);
                else
                    st.top() += curr;
            }
        }
        return st.top();
    }
};