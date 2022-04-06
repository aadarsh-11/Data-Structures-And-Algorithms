class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int> count; 
        vector<int> v;
        int mod = 1e9+7;
        for(auto i: arr)
        {
            if(++count[i] == 1)
            {
                // cout<<i<<" ";
                v.push_back(i);
            }
        }
        sort(v.begin(),v.end());
        // cout<<endl;
        long long ans = 0;
        for(int i = 0 ; i < v.size(); i++)
        {
            int ct = target-v[i];
            if(ct < 0) break;
            int l = i, r = v.size()-1;
            while(l<=r)
            {
                if(v[l] + v[r] == ct)
                {
                    if(i == l and i == r)
                    {
                        long long n = count[v[i]];
                        ans += (n*(n-1)*(n-2))/6;
                    }
                    else if(i == l)
                    {
                        int n = count[v[l]];
                        ans += count[v[r]]*(n*(n-1))/2;
                    }
                    else if(l == r)
                    {
                        int n = count[v[l]];
                        ans += count[v[i]]*(n*(n-1))/2;
                    }
                    else
                    {
                        ans += count[v[i]]*count[v[l]]*count[v[r]];
                    }
                    ans %= mod;
                    // cout<<i<<" "<<l<<" "<<r<<" "<<ans<<endl;
                    l++;
                }
                else if(v[l]+v[r] > ct) r--;
                else l++;
            }
        }
        return (int)ans;
    }
};