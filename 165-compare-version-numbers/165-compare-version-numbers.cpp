class Solution {
public:
    int compareVersion(string x, string y) {
        queue<int> q1,q2;
        
        string s = "";
        for(auto i:x)
        {
            if(i == '.')
            {
                q1.push(stoi(s));
                s = "";
            }
            else
            {
                s += i;
            }
        }
        q1.push(stoi(s));
        
        s = "";
        for(auto i:y)
        {
            if(i == '.')
            {
                q2.push(stoi(s));
                s = "";
            }
            else
            {
                s += i;
            }
        }
        q2.push(stoi(s));
        
        while(!q1.empty() and !q2.empty() and q1.front() == q2.front())
        {
            q1.pop();
            q2.pop();
        }
        
        if(q1.empty())
        {
            while(!q2.empty() and q2.front() == 0) q2.pop();
        }
        if(q2.empty())
        {
            while(!q1.empty() and q1.front() == 0) q1.pop();
        }
        
        if(q1.empty() and q2.empty()) return 0;
        if(q1.empty()) return -1;
        if(q2.empty()) return 1;
        
        return q1.front() > q2.front() ? 1 : -1;
    }
};