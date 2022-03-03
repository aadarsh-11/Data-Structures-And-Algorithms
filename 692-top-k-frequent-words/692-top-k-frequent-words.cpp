class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto i: words)
        {
            mp[i]++;
        }
        
        vector<pair<string, int>> v;
        for(auto i: mp)
        {
            v.push_back(i);
        }
        
        sort(v.begin(), v.end(), [&](pair<string,int> &s, pair<string, int> &b)
            {
                if(s.second == b.second) return s.first<=b.first;
                return s.second > b.second;
            });
        
        words.clear();
        for(auto i: v)
        {
            words.push_back(i.first);
            if(words.size() == k) break;
        }
        return words;
    }
};