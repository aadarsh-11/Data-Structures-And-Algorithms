class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> pre = cardPoints;
        for(int i = 1 ; i < n; i++)
        {
            pre[i] += pre[i-1];
            cardPoints[n-i-1] += cardPoints[n-i];
        }
        int ans = max(pre[k-1], cardPoints[n-k]);
        
        if(k == 1) return ans;
        for(int i = 1 ; i <k ; i++)
        {
            ans = max(ans, pre[k-i-1] + cardPoints[n-i]);
        }
        
        return ans;
    }
};