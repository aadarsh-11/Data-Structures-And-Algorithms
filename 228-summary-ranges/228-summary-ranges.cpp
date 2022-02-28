class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        vector<pair<int,int>> range;
        pair<int,int> x;
        bool flag = 1;
        for(int i = 0; i< nums.size(); i++)
        {
            if(flag)
            {
                x = {nums[i],nums[i]};
                flag = 0;
            }
            else
            {
                if(nums[i] == nums[i-1]+1)
                {
                    x.second = nums[i];
                }
                else
                {
                    range.push_back(x);
                    flag = 1;
                    i--;
                }
            }
        }
        if(!flag)
        {
            range.push_back(x);
        }
        for(auto x: range)
        {
            if(x.first == x.second)
            {
                ans.push_back(to_string(x.first));
                continue;
            }
            string s = to_string(x.first) + "->" + to_string(x.second);
            ans.push_back(s);
        }
        return ans;
    }
};