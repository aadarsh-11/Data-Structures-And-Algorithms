class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int r = people.size()-1;
        int l = 0;
        int ans = 0;
        while(l<r)
        {
            if(people[l]+people[r] <= limit)
            {
                l++;
                r--;
                ans++;
            }
            else
            {
                r--;
                ans++;
            }
        }
        if(l == r) ans++;
        return ans;
    }
};