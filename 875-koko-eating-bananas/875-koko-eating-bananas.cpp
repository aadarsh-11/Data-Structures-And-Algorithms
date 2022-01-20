class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        sort(a.begin(), a.end());
        int n = a.size();
        
        int left = 1;
        int right = a.back();
        int sol = a.back();
        
        while(left < right)
        {
            int ans = 0;
            int mid = (left+right)/2;
            // cout<<left<<", "<<right<<", ";
            // cout<<mid<<" : ";
            for(auto i: a)
            {
                ans += i/mid;
                ans += (i%mid==0? 0: 1);
            }
            // cout<<ans<<endl;
            if(ans <= h)
            {
                sol = min(sol, mid);
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return sol;
    }
};