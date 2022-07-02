class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1e9+7;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxh = horizontalCuts[0];
        for(int i = 1; i < horizontalCuts.size(); i++)
            maxh = max(maxh, horizontalCuts[i] - horizontalCuts[i-1]);
        maxh = max(maxh, h - horizontalCuts.back());
        
        int maxw = verticalCuts[0];
        for(int i = 1; i < verticalCuts.size(); i++)
            maxw = max(maxw, verticalCuts[i] - verticalCuts[i-1]);
        maxw = max(maxw, w - verticalCuts.back());
        
        return (int)((long long)maxh*(long long)maxw % mod);
    }
};