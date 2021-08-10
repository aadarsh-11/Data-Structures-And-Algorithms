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
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int ans = n;
        int dp[n+1], dp2[n+2];
        dp[0] = 0;
        // dp2[n] = 0;
        fab(0,n,i)
        {
            if(s[i] == '1')
            {
                dp[i+1] = dp[i]+1;
            }
            else
            {
               dp[i+1] = dp[i];
            }
        }
        fo(i,n+1)
        {
            ans = min(ans, dp[i] + n-i - (dp[n]-dp[i]));
        }
        return ans;
    }
};