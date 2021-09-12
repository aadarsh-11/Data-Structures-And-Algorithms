class Solution {
public:
    bool canJump(vector<int>& a) {
        int mx = a[0];
        int n = a.size();
        int i = 0;
        if(i >= n-1) return true;
        while(mx>0)
        {
            i++;
            if(i >= n-1) return true;
            mx--;
            mx = max(mx, a[i]);
        }
        return false;
    }
};