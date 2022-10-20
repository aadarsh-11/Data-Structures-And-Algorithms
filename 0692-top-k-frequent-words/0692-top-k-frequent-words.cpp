class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto i: words)
        {
            mp[i]++;
        }
        
        auto myComparator = [](pair<int, string> &p1, pair<int, string> &p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        };
        
        priority_queue<pair<int, string>,vector<pair<int, string>>, decltype(myComparator)> pq(myComparator);
        for(auto i: mp)
        {
            pq.push({i.second, i.first});
            if(pq.size() > k) pq.pop();
        }
        // vector<string> words;
        words.clear();
        while(!pq.empty())
        {
            words.push_back(pq.top().second);
            pq.pop();
        }
        reverse(words.begin(), words.end());
        return words;
    }
};