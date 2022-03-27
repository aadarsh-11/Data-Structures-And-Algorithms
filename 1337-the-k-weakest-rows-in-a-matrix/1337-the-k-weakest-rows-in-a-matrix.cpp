class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        for(int i = 0 ; i< mat.size(); i++)
        {
            int l = 0;
            int r = mat[i].size()-1;
            
            while(l<=r)
            {
                int mid = l + (r-l)/2;
                if(mat[i][mid] == 0)
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            
            v.push_back({l,i});
        }
        sort(v.begin(),v.end());
        vector<int> ans(k);
        for(int i = 0 ; i< k ; i++)
        {
            ans[i] = v[i].second;
        }
        return ans;
    }
};