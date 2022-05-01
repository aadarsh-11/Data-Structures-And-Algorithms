class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string st1,st2;
        
        for(auto i: s)
        {
            if(i == '#')
            {
                if(st1.size()) st1.pop_back();
            }
            else st1 += i;
        }
        
        for(auto i: t)
        {
            if(i == '#')
            {
                if(st2.size()) st2.pop_back();
            }
            else st2 += i;
        }
        
        return st1 == st2;
    }
};