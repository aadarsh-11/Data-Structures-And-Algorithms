class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        map<int ,int> col,row;
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(a[i][j] == 0)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(row[i] or col[j])
                {
                    a[i][j] = 0;
                }
            }
        }
    }
};