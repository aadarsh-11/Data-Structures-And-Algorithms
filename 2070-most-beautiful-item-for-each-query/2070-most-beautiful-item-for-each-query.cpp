class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        for(int i = 1; i < items.size(); i++)
        {
            items[i][1] = max(items[i][1],items[i-1][1]);
        }
        vector<int> res;
        for(auto &q: queries)
        {
            int l = 0 ;
            int r = items.size()-1;
            while(l<r)
            {
                int mid = (l+r)/2;
                if(items[mid][0] <= q)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
            if(items[l][0] > q) l--;
            if(l<0)
                res.push_back(0);
            else 
                res.push_back(items[l][1]);
        }
        return res;
    }
};