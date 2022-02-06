class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int curr = 0;
        int cnt = 1;
        for(int i =1 ; i < a.size(); i++)
        {
            if(a[i] == a[curr])
            {
                cnt++;
                if(cnt<=2)
                {
                    a[++curr] = a[i];
                }
            }
            else
            {
                a[++curr] = a[i];
                cnt = 1;
            }
            
        }
        return curr+1;
    }
};