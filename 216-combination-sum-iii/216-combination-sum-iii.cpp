class Solution {
public:
    void f(int k, int n, int mx, vector<int> &curr, vector<vector<int>> &a)
    {
        if(k == 1)
        {
            if(n>0 and n<mx)
            {
                curr.push_back(n);
                a.push_back(curr);
                curr.pop_back();
            }
            return;
        }
        for(int i = mx-1; i>0 ; i--)
        {
            curr.push_back(i);
            f(k-1,n-i,i, curr, a);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>curr;
        f(k,n,10,curr, ans);
        return ans;
    }
};