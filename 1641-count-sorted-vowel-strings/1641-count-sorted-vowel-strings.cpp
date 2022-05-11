class Solution {
public:
    int countVowelStrings(int n) {
        // its like number of ways to put 4 zeroes in n ones, so its n+4 c 4
        return ((n+4)*(n+3)*(n+2)*(n+1))/24;
    }
};