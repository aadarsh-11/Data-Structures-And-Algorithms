class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans, temp;
        if(digits.size()==0) return ans;
        ans.push_back("");
        for(auto d: digits)
        {
            for(auto i: ans)
            {
                if(d-'0'<7)
                {                    
                    temp.push_back(i+(char)((d-'2')*3+'a'));
                    temp.push_back(i+(char)((d-'2')*3+1+'a'));
                    temp.push_back(i+(char)((d-'2')*3+2+'a'));
                }
                else if(d == '7')
                {
                    temp.push_back(i+"p");
                    temp.push_back(i+"q");
                    temp.push_back(i+"r");
                    temp.push_back(i+"s");
                }
                else if(d == '8')
                {
                    temp.push_back(i+"t");
                    temp.push_back(i+"u");
                    temp.push_back(i+"v");
                }
                
                else if(d == '9')
                {
                    temp.push_back(i+"w");
                    temp.push_back(i+"x");
                    temp.push_back(i+"y");
                    temp.push_back(i+"z");
                }
            }
            ans = temp;
            temp.clear();
        }
        return ans;
    }
};