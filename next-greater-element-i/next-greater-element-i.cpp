#define pb push_back

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(auto i: nums1)
        {
            bool flag = 0;
            for(auto j: nums2)
            {
                if(i == j) flag = 1;
                if(flag)
                {
                    if(j>i)
                    {
                        flag = 0;
                        ans.pb(j);
                        break;
                    }
                }
            }
            if(flag) ans.pb(-1);
        }
        return ans;
    }
};