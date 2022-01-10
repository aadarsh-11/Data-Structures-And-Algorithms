class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int c = 0;
        int n = a.size()-1;
        int m = b.size()-1;
        while(n >=0 or m>=0 or c> 0)
        {
            c += (n>=0 ? a[n--] - '0' : 0);
            c += (m>=0 ? b[m--] - '0' : 0);
            s = (char)(c%2 + '0') + s;
            c /= 2;
        }
        return s;
    }
};