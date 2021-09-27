class Solution {
public:
    int numUniqueEmails(vector<string>& s) {
        map<string,int> mp;
        int n =s.size();
        for(int i = 0 ; i< n ; i++)
        {
            string a = "";
            for(int j = 0 ; j < s[i].size(); j++)
            {
                if(s[i][j] == '@')
                {
                    while(j < s[i].size()) 
                    {
                        a += s[i].substr(j,1);
                        j++;
                    }
                    
                }
                if(s[i][j] == '+')
                {
                    while(s[i][j] != '@')j++;
                    j--;
                    continue;
                }
                if(s[i][j] == '.')
                    continue;
                a += s[i].substr(j,1);
            }
            mp[a]++;
        }
        return mp.size();
    }
};