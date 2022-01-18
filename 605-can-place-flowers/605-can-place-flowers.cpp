class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        if(a.size() == 1)
        {
            n -= 1-a[0];
            return n<=0;
        }
        for(int i = 0; i<a.size()-1; i++)
        {
            if(a[i] == 0 and a[i+1] == 0)
            {
                a[i] = 1;
                n--;
                i++;
            }
            else
            {
                while(i<a.size() and a[i] == 1) i++;
            }
        }
        if(a.back() == 0 and a[a.size()-2] == 0) n--;
        return n<=0;
    }
};