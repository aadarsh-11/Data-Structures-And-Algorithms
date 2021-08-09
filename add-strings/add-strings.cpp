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
    string addStrings(string s1, string s2) {
        reverse(all(s1));
        reverse(all(s2));
        string ans = "";
        int n = min (s1.size(), s2.size());
        int n2 = max (s1.size(), s2.size());
        int carry = 0;
        fo(i,n)
        {
            int x;
            x = (s1[i]-'0' + s2[i]-'0' + carry);
            
            carry = x/10;
            x = x%10;
            ans = to_string(x) + ans;
        }
        s1 = (s1.size() > s2.size() ? s1 : s2);
        n2 = n2-n;
        fo(i,n2)
        {
            int x;
            x = (s1[n+i]-'0'+ carry);
            
            carry = x/10;
            x = x%10;
            ans = to_string(x) + ans;
        }
        if(carry > 0)
        ans = to_string(carry) + ans;
        return ans;
    }
};