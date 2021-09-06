class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        string x = s;
        int n = s.size();
        for(int i = 0 ; i < n; i++)
        {
            x = min(x,s);
            s = s.substr(1,n-1)+s.substr(0,1);
        }
        return x;
    }
};