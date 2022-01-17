class Solution {
public:
    bool cmp(string &s,string &t)
    {
        int d = 0;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] != t[i]) d++;
        }
        return d == 1;
    }
    int ladderLength(string b, string e, vector<string>& a) {
        bool found=0;
        set<string> st;
        for(auto i: a)
        {
            st.insert(i);
            if(i == e)
            {
                found = 1;
            }
        }
        if(!found) return 0;
        
        queue<string> q;
        q.push(b);
        
        int ans = 2;
        while (!q.empty())
        {
            int n = q.size();
            vector<string> v;
            while(n--)
            {
                string s = q.front();
                q.pop();
                
                for(int i = 0 ; i <s.size(); i++)
                {
                    string temp = s;
                    for(char c = 'a' ; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        if(temp == s) continue;
                        if(temp == e) return ans;
                        if(st.find(temp) != st.end())
                        {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};