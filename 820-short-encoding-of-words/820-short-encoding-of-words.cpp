class Solution {
public:
    bool cmp(string &s1,string &s2)
    {
        int i = s1.size()-1;
        int j = s2.size()-1;
        while(j>=0 and s1[i] == s2[j])
        {
            i--;
            j--;
        }
        return j == -1;
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string &s1,string &s2) {
            return s1.size() < s2.size();
        });
        
        int cnt = words.size();
        int len = 0;
        
        for(int i = 0 ; i < words.size(); i++)
        {
            string s = words[i];
            len += s.size();
            for(int j = words.size()-1; j > i; j--)
            {
                string t = words[j];
                if(cmp(t,s))
                {
                    len -= s.size();
                    cnt--;
                    break;
                }
            }
        }
        return len+cnt;
    }
};