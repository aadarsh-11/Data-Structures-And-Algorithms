class Solution {
public:
    int pre(string s, int i)
    {
        if(i == -1 or i>=s.size()) return -1;
        
        // cout<<i<<' '<<s[i]<<endl;
        if(s[i] == '#')
        {
            return i+2;
        }
        // cout<<"i+2: " << i+2<<endl;
        while(s[i] != ',') 
        {
            i++;
            if(i>= s.size()) return -1;
        }
        
        int x = pre(s, i+1);
        // cout<<x<<endl;
        return pre(s,x);
    }
    bool isValidSerialization(string preorder) {
        int i = pre(preorder, 0);
        return (i == preorder.size()+1);
    }
};