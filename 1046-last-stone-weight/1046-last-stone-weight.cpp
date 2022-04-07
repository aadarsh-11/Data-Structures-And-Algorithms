class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i: stones)
        {
            pq.push(i);
        }
        int x,y;
        while(pq.size()>=2)
        {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            x = abs(x-y);
            if(x) pq.push(x);
        }
        return pq.empty() ? 0: pq.top();
    }
};