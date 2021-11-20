class Solution {
public:
    string getHint(string a, string b) {
        map<char,int> mp1,mp2;
        int x = 0, y = 0;
        int n = a.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(a[i] == b[i])
                x++;
            else
            {
                mp1[a[i]]++;
                mp2[b[i]]++;
            }
        }
        for(auto i: mp1)
        {
            y += min(mp2[i.first], i.second);
        }
        string ans = to_string(x) + "A" + to_string(y) + "B";
        return ans;
    }
};