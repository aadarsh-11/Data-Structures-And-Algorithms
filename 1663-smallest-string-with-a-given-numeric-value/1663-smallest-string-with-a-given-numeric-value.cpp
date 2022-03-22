class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n,'a');
        k -= n;
        
        while(k>0)
        {
            if(k>=25)
            {
                k -= 25;
                s[--n] = 'z';
            }
            else
            {
                s[--n] += k;
                k = 0;
            }
        }
        return s;
    }
};