class Solution {
public:
    int make_bitset(string s)
    {
        int ans = 0;
        for(auto i:s)
        {
            ans = ans | (1<<(i-'a'));
        }
        return ans;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        map<int, int> mp;
        for(auto i: words)
        {
            mp[make_bitset(i)]++;
        }
        int i = 0;
        vector<int> ans(puzzles.size(),0);
        for(auto p: puzzles)
        {
            int mask = make_bitset(p);
            int submask = mask;
            int first = (1<<(p[0]-'a'));
            while(submask)
            {
                if(submask & first)
                {
                    ans[i] += mp[submask];
                }
                submask = mask & (submask-1);
            }
            i++;
        }
        return ans;
    }
};