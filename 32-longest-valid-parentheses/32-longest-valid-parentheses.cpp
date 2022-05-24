class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> st;
        int ans = 0;
        st.push({'#',-1});
        for(int i = 0 ; i< s.size(); i++)
        {
            if(s[i] =='(')
            {
                st.push({s[i],i});
            }
            else
            {
                if(st.top().first == '#')
                {
                    st.top().second = i;
                    continue;
                }
                else
                {
                    st.pop();
                    ans = max(ans, i-st.top().second);
                }
            }
        }
        return ans;
    }
};