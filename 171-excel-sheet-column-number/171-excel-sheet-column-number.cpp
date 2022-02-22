class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            //for ans of len i;
            ans += pow(26,i);
            
            //for all characters at position i less tha s[i]
            int x = s[i]-'A';
            ans += pow(26,n-i-1)*x;
        }
        return ans;
    }
};