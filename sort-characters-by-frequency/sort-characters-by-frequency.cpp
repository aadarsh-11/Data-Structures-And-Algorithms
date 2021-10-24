class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char,int> mp;
        for(int i = 0 ; i< n ; i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,char>> v;
        for(auto i:mp)
        {
            v.push_back({i.second, i.first});
        }
        sort(v.rbegin(), v.rend());
        for(auto i:v)
        {
            cout<<i.first<<i.second<<endl;
        }
        string ans = "";
        for(auto i: v)
        {
            string  y="";
            for(int j = 0; j< i.first; j++)
                ans+= i.second;
        }
        return ans;
    }
};