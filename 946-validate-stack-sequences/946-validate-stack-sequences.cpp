class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int i = 0, j = 0;
        int n = pushed.size();
        while(j<n and i<n)
        {
            if(st.empty())
            {
                st.push(pushed[i++]);
            }
            else
            {
                if(st.top() == popped[j])
                {
                    st.pop();
                    j++;
                }
                else
                {
                    st.push(pushed[i++]);
                }
            }
        }
        while(!st.empty() and st.top() == popped[j])
        {
            st.pop();
            j++;
        }
        return (i==n and j == n);
    }
};