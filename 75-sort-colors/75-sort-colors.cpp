class Solution {
public:
    void sortColors(vector<int>& a) {
        int start = 0;
        int end = a.size()-1;
        
        for(int i = 0 ; i< a.size(); i++)
        {
            if(i< end)
            {
                if(a[i] == 2)
                {
                    swap(a[i], a[end]);
                    end--;
                    i--;
                }
            }
            if(start < i)
            {
                if(a[i] == 0)
                {
                    swap(a[i], a[start]);
                    start++;
                    i--;
                }
            }
        }
    }
};