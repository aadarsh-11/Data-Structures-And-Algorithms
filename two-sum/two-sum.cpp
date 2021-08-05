class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        unordered_map<int,int>mp;
        int n = a.size();
        for(int i =0; i <n; i++)
        {
            mp[a[i]] = i+1;
        }
        vector<int>ans;
        for(int i = 0 ; i < n; i++)
        {
            if(mp[target-a[i]] and mp[target-a[i]] != i+1)
            {
                ans.push_back(i);
                ans.push_back(mp[target-a[i]]-1);
                break;
                
            }
        }
        return ans;
    }
};