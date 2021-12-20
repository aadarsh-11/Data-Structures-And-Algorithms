class Solution {
public:
    int isdig(char c)
    {
        if(c-'0' >=0 and c-'0' <10) return 1;
        return 0;
    }
    string decodeString(string s) {
        stack<pair<string, int>>st;
        int n = 0;
        st.push({"",1});
        for(int i = 0 ; i< s.size(); i++)
        {
            if(isdig(s[i]))
            {
                n*=10;
                n+= s[i]-'0';
            }
            else
            {
                if(s[i] == ']')
                {
                    int x = st.top().second;
                    string y = st.top().first;
                    string z = "";
                    for(int j = 0 ; j < x; j++)
                    {
                        z += y;
                    }
                    st.pop();
                    st.top().first += z;
                }
                else if(s[i] == '[')
                {
                    st.push({"",n});
                    n = 0;
                }
                else
                {
                    st.top().first += s[i];
                }
            }
        }
        return st.top().first;
    }
};