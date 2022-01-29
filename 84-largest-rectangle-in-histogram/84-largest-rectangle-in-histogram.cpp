class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<vector<int>> st;
        int n = h.size();
        int ans = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(st.empty())
            {
                st.push({h[i],i});
                ans = max(ans,h[i]);
            }
            else
            {
                int ti = i-1;
                int lastInd = ti;
                bool flag = 0;
                while(!st.empty() and st.top()[0] > h[i])
                {
                    flag = 1;
                    int height2 = st.top()[0];
                    lastInd = st.top()[1];
                    ans = max(ans, height2*(ti-st.top()[1]+1));
                    // cout<<i<<"--"<<ans<<" "<<height2<<" "<<st.top()[1]<<endl;
                    st.pop();
                }
                if(flag)
                    st.push({h[i],lastInd});
                else
                    st.push({h[i],i});
                ans = max(ans, h[i]);
            }
            // cout<<i<<" : "<<ans<<endl;
        }
        if(!st.empty())
        {
            st.push({h[n-1],n-1});
            int ti = st.top()[1];
            while(!st.empty())
            {
                int height2 = st.top()[0];
                ans = max(ans, height2*(ti-st.top()[1]+1));
                st.pop();
            }
        }
        return ans;
    }
};