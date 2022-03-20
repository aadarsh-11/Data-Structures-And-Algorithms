class Solution {
public:
    int binsearch(int q , vector<vector<int>> &items)
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
        if(l<0) return 0;
        return items[l][1];
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        for(int i = 1; i < items.size(); i++)
        {
            items[i][1] = max(items[i][1],items[i-1][1]);
        }
        vector<int> ans;
        for(auto &i: queries)
        {
            ans.push_back(binsearch(i, items));
        }
        return ans;
    }
};