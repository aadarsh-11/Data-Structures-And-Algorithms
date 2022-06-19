class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        int n = products.size();
        int l = 0, r = n-1;
        
        int i = 0;
        for(auto q: searchWord)
        {
            while(l<=r and products[l][i] != q)l++;
            while(l<=r and products[r][i] != q)r--;
            
            vector<string> ans;
            
            for(int j = l; j<=min(l+2,r); j++)
            {
                ans.push_back(products[j]);
            }
            res.push_back(ans);
            i++;
        }
        return res;
    }
};