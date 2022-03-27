class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        priority_queue<pair<int,int>> pq;
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
            
            pq.push({l,i});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans(k);
        for(int i = 0 ; i<k; i++)
        {
            ans[k-i-1] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};