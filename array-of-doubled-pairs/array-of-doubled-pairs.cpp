#define fab(a,b,i) for(int i=a; i<b; i++)
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define eb emplace_back
#define db double
#define mp make_pair
#define mt make_tuple
#define endl "\n"
#define f first
#define se second
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << "=" << x << endl
#define cdeb(x,y) cout << x << " " << y << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define boost ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define mod 1000000007

class Solution {
public:
    bool canReorderDoubled(vector<int>& a) {
        int n = a.size();
        map<int,int>ma;
        int ans = 0;
        fo(i,n)
        {
            ma[a[i]]++;
            // if(a[i]%2 and a[i] != 1 and a[i] != -1)
            //     return false;
        }
        sort(all(a));
        fo(i,n)
        {
            if(a[i] >=0)break;
            if(ma[a[i]])
            {
                if(a[i]%2 == 0 and ma[a[i]/2])
                {
                    ma[a[i]]--;
                    ma[a[i]/2]--;
                }
                else
                {
                    return false;
                }
            }
        }
        for(int i = n-1; i >=0; i--)
        {
            if(ma[a[i]])
            {
                if(a[i]%2 == 0 and ma[a[i]/2])
                {
                    ma[a[i]]--;
                    ma[a[i]/2]--;
                }
                else
                {
                    return false;
                }
            }
        }
        for(auto i: ma)
        {
            ans += i.se;
        }
        if(ans>0) return false;
        return true;
    }
};