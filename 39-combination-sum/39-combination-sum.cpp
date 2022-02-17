class Solution {
public:
    set<vector<int>> ans;
    void rec(vector<int>& a, vector<int>& temp, int target, int x)
    {
        if(target == 0)
        {
            ans.insert(temp);
            return;
        }
        if(x>=a.size() or target < a[x]) return;
        
        temp.push_back(a[x]);
        rec(a,temp,target-a[x],x);
        temp.pop_back();
        rec(a,temp, target, x+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        rec(candidates,v, target, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};