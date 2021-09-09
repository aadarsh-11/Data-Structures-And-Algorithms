class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        for(int i = 1 ; i< n ; i++)
        {
            shifts[n-i-1] += shifts[n-i];
            shifts[n-i-1] %= 26;
        }
        for(int i = 0 ; i < n ; i++)
        {
            char x = s[i];
            x = (char)(97 + (x-'a' + shifts[i])%26);
            s[i] = x;
        }
        return s;
    }
};