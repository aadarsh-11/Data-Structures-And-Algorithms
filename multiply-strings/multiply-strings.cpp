class Solution {
public:
    string multiply(string a, string b) {
        int carr = 0;
        int ld = 0;
        int n = a.size();
        int m = b.size();
        reverse(a.begin(),a.end());
        reverse(b.begin(), b.end());
        map<int,int> mp;
        for(int i = 0 ; i < n; i++)
        {
            for(int j=0;j < m; j++)
            {
                mp[i+j] += (a[i]-'0')*(b[j]-'0');
            }
        }
        int x = max(n,m)*2;
        string ans(x, '0');
        for(int i = 0 ; i<=x; i++)
        {
            ans[i] = '0'+mp[i]%10;
            mp[i+1]+=mp[i]/10;
        }
        reverse(ans.begin(), ans.end());
        ans.erase(0, min(ans.find_first_not_of('0'), ans.size()-1));
        return ans;
    }
};