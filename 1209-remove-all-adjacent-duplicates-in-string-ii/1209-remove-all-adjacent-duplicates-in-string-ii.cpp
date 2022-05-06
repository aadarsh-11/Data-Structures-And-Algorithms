class Solution {
public:
    string removeDuplicates(string s, int k) {
        s += "#";
        stack<pair<char,int>> st;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(!st.empty())
            {
                if(st.top().first == s[i]) 
                {
                    st.top().second++;
                    if(st.top().second == k) st.pop();
                }
                else
                {
                    if(st.top().second == k)
                    {
                        st.pop();
                        i--;
                        continue;
                    }
                    else
                    {
                        st.push({s[i],1});
                    }
                }
            }
            else
            {
                st.push({s[i],1});
            }
        }
        st.pop();
        string ans = "";
        while(!st.empty())
        {
            string temp = "";
            for(int i = 0; i < st.top().second; i++)
            {
                temp += st.top().first;
            }
            temp += ans;
            ans = temp;
            st.pop();
        }
        return ans;
    }
};