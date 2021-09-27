#define pb push_back

class Solution {
public:
    void helper(vector<int> a, vector<vector<int>> &ans, int l, int r)
    {
        if(l == r)
        {
            ans.pb(a);
            return;
        }
        for(int i = l; i < r; i++)
        {
            swap(a[l], a[i]);
            helper(a, ans,l+1, r);
            swap(a[l], a[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,ans,0,nums.size());
        return ans;
    }
};