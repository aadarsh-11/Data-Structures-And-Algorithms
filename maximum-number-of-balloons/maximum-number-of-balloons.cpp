class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balon";
        map<char,int> mp;
        for(auto i: s)
        {
            mp[i] = 0;
        }
        for(auto i: text)
        {
            for(auto j:s)
            {
                if(j == i)
                {
                    mp[j]++;
                }
            }
        }
        mp['l'] /= 2;
        mp['o'] /= 2;
        int ans = INT_MAX;
        for(auto i: mp)
        {
            ans = min(ans, i.second);
        }
        return ans;
    }
};