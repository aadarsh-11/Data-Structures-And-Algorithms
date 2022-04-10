class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        stack<int> rec;
        for(auto i: ops)
        {
            if(i == "C") rec.pop();
            else if(i == "D")
            {
                rec.push(rec.top()*2);
            }
            else if(i == "+")
            {
                int pre = rec.top();
                rec.pop();
                int curr = rec.top() + pre;
                rec.push(pre);
                rec.push(curr);
            }
            else
            {
                rec.push(stoi(i));
            }
        }
        while(!rec.empty())
        {
            ans += rec.top();
            rec.pop();
        }
        return ans;
    }
};