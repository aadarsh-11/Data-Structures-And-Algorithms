class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;
        vector<string> v(n,"");
        int t = 1;
        int i = 0;
        bool flag = 1;
        for(auto c: s)
        {
            v[i]+=c;
            if(flag)
            {
                if(i == v.size()-1)
                {
                    flag = 0;
                    i--;
                }
                
                else
                {
                    i++;
                }
            }
            else
            {
                if(i == 0)
                {
                    flag = 1;
                    i++;
                }
                else
                {
                    i--;
                }
            }
        }
        s = "";
        for(auto i: v)
            s += i;
        return s;
    }
};