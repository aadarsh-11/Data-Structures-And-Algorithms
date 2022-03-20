class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a = tops[0];
        int b = bottoms[0];
        
        int n = tops.size();
        int atc = 1, bbc = 1;
        int abc = 0, btc = 0;
        for(int i = 1 ; i < n; i++)
        {
            if(tops[i] == bottoms[i])
            {
                if(tops[i] != a) a = -1;
                if(tops[i] != b) b = -1;
                continue;
            }
            if(tops[i] == a) atc++;
            else if(bottoms[i] != a) a = -1;
            else abc++;
            
            if(bottoms[i] == b) bbc++;
            else if(tops[i] != b) b = -1;
            else btc++;
        }
        
        if(a == -1 and b == -1) return -1;
        
        int ans = INT_MAX;
        if(a>0)
        {
            ans = min(atc, abc);
        }
        if(b>0)
        {
            ans = min({ans,bbc,btc});
        }
        return ans;
    }
};