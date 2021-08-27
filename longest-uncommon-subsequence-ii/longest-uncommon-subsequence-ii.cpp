class Solution {
public:
    bool issub(string s1,string s2)
    {
        int n = s1.size();
        int m = s2.size();
        int i = 0 ;
        int j = 0;
        while(i<n)
        {
            if(s1[i] == s2[j])
                j++;
            i++;
        }
        return j == m;
    }
    int findLUSlength(vector<string>& strs) {
        if(strs.size() == 1) return -1;
        sort(strs.begin(), strs.end(), [](string& a,string& b){
           return a.length()>b.length(); 
        });
        bool flag = 0;
        for(int i = 0 ; i<strs.size();i++)
        {
            cout<<strs[i]<<endl;
            flag = 0;
            for(int j = 0 ; j < strs.size() and strs[i].size() <= strs[j].size(); j++)
            {
                if(i!=j and issub(strs[j], strs[i]))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            return strs[i].size();
        }
        return -1;
    }
};