class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b)
    {
        if(a[1] < b[1]) return true;
        else if(a[1] == b[1]) return a[2] < b[2];
        return false;
    }
    
    bool carPooling(vector<vector<int>>& trips, int cap) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>st;
        
        sort(trips.begin(), trips.end(), cmp);
        for(auto i: trips)
        {
            while(!st.empty() and st.top().first <= i[1])
            {
                cap += st.top().second;
                st.pop();
            }
            
            if(cap >= i[0])
            {
                cap -= i[0];
                st.push({i[2], i[0]});
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};