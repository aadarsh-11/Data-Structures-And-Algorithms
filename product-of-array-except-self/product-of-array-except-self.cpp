class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n), post(n);
        pre[0] = a[0];
        post[n-1] = a[n-1];
        for(int i = 1; i < n ; i++)
        {
            pre[i] = a[i]*pre[i-1];
            post[n-1-i] = a[n-1-i]*post[n-i];
        }
        a[0] = post[1];
        a[n-1] = pre[n-2];
        for(int i = 1 ; i< n-1 ; i++)
        {
            a[i] = pre[i-1]*post[i+1];
        }
        return a;
    }
};