class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l = 0, r = tokens.size()-1;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        while(l<=r)
        {
            if(tokens[l] <= power)
            {
                score++;
                power -= tokens[l++];
            }
            else if(l < r and score > 0)
            {
                score--;
                power += tokens[r--];
            }
            else break;
        }
        return score;
    }
};