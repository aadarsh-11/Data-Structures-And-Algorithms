class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        stack<pair<int,int>> st;
        vector<int> ans(a.size(),0);
        for(auto &t: a)
        {
            int i = &t-&a[0];
            
            while(!st.empty())
            {
                if(st.top().first < t)
                {
                    ans[st.top().second] = i-st.top().second;
                    st.pop();
                }
                else
                    break;
            }            
            st.push({t,i});            
        }
        return ans;
    }
};