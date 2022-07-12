class Solution {
public:
    bool rec(int ind, vector<int>& vis,int cs, vector<int>&a, int target, int k)
    {
        if(k == 1) return 1;
        if(target == cs) return rec(0,vis,0,a,target,k-1);

        for(int i = ind; i<a.size(); i++)
        {
            if(!vis[i] and target - a[i] >= cs)
            {
                vis[i] = 1;
                if(rec(i+1,vis,cs+a[i],a,target,k)) return true;
                vis[i] = 0;
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(),0);
        if(a.size()<4 or sum%4) return 0;
        
        sort(a.rbegin(), a.rend());
        
        vector<int>vis(a.size(),0);
        
        return rec(0,vis,0,a,sum/4, 4);
    }
};