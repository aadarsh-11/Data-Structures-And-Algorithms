class Solution {
public:
    int bitwiseComplement(int n) {
        int i = 1;
        while(i<n)
        {
            i = i<<1 |1;
        }
        return n^i;
    }
};