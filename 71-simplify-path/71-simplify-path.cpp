class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans = "";
        string curr = "";
        path += "/";
        for(auto i: path)
        {
            if(i == '/')
            {
                if(curr == "..")
                {
                    if(!st.empty()) st.pop();
                }
                else if(curr != "" and curr != ".")
                {
                    st.push(curr);
                }
                curr = "";
            }
            else
            {
                curr+=i;
            }
        }
        while(!st.empty())
        {
            ans = "/"+ st.top() + ans; 
            st.pop();
        }
        if(ans == "") ans = "/";
        return ans;
    }
};