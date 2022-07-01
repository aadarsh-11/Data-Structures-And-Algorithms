class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> &a, vector<int>&b){
            return a[1] >= b[1];
        });
        int ans = 0;
        
        for(auto i: boxTypes)
        {
            if(i[0]<truckSize)
            {
                ans += i[0]*i[1];
                truckSize -= i[0];
            }
            else
            {
                ans += i[1] * truckSize;
                break;
            }
        }
        return ans;
    }
};