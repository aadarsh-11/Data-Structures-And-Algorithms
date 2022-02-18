class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for(int i = 0 ; i<n; i++)
        {
            for(int j = i ; j <n; j++)
            {
                if(i == j) continue;
                swap(a[i][j], a[j][i]);
            }
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                // if(i == j) continue;
                swap(a[i][j], a[i][n-j-1]);
            }
        }
    }
};