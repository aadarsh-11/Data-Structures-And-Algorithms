class Solution {
public:
    map<string , int> ma;
    int numDecodings(string s) {
        if(ma[s]) return ma[s];
        if(s[0] == '0') return 0;
        if(s.size() < 2)
            return 1;
        int n = s.size();
        ma[s] = numDecodings(s.substr(1,n-1));
        if(s[0] == '1' or (s[0] == '2' and s[1] - '0' <= 6))
        {
            ma[s] += numDecodings(s.substr(2,n-2));
        }
        return ma[s];
    }
};