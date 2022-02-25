class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        int i = 1;
        for(int j = 1 ; j < n; j++)
        {
            if(a[j] != a[j-1])
            {
                a[i++] = a[j];
            }
        }
        return i;
    }
};