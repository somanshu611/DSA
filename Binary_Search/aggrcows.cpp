#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define gc getchar_unlocked
#define rep(i,a,b) for(int i=a;i<=b;i++)
// #define rep(i,a) rep(i,0,a)
#define per(i,b,a) for(int i=b;i>=a;i--)
// #define per(i,a) per(i,0,a)
#define INF 1e18
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define pf push_front
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD1 1000000007
#define MOD2 998244353
#define INF 1e18
#define arrlen(ar) (sizeof(ar)/sizeof(ar[0]))

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int>	pii;
typedef pair<ll,ll> pll;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<bool>		vb;
typedef vector<ll>      vll;
typedef vector<string>  vs;
typedef vector<pii>		vpii;
typedef vector<pll> vpll;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector<vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector<vector<T>> v) {for(auto &c : v) {_print(c);cerr<<nl;} }
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*---------------------------------------------------------------------------------------------------------*/
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll ceil_div(ll a,ll b) {return (a+b-1)/b;}
int ceil_div(int a,int b) {return (a+b-1)/b;};
void swap(string &a,string &b) {string temp=a;a=b;b=temp;}
ll lcm(ll a,ll b) {return (abs(a*b)/gcd(a,b));}
ll fact(ll n) {ll ans=1;while(n>1) {ans=(1LL*ans*n)%MOD1;n--;}return ans;}
ll pw(ll a,ll b) {long long res = 1;while (b > 0) {if (b & 1)res = (res * a)%MOD1;a=(a * a)%MOD1;b >>= 1;}return res;}
ll setBitNumber(ll n) {int k=(int)log2(n);return 1<<k;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
bool ispower2(ll n){return(n and (n&(n-1))==0 );}
ll lg2(ll n){ll cnt=0;int temp=n;while(temp>1){temp/=2;cnt++;}if(ispower2(n) ) return cnt;else return cnt+1;} 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_mul(ll a,ll b,ll m) {a=a%m;b=b%m;return ((a*b)%m);}
ll mod_sub(ll a,ll b,ll m) {a=a%m;b=b%m;return (((a-b)%m + m)%m);}
ll mod_div(ll a,ll b,ll m) { a=a%m;b=b%m;return (mod_mul(a,mod_expo(b,m-2,m),m)%m);} // 'm' must be prime
ll nmod(ll n,ll k) {if(n>0) return n%k;else return (n+k*(ceil_div(abs(n),k)));}
/*---------------------------------------------------------------------------------------------------------*/

bool check(vector<int> &v,int k,int c) {
    int n = v.size();
    int prev = v[0],cnt=1;
    for(int i=1;i<n;i++) {
        if((v[i]-prev)>=k) {
            prev = v[i];
            cnt++;
        }
    }
    debug(make_pair(cnt,c));
    return cnt>=c;
}
bool solve() {
    int n,c;cin>>n>>c;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    int l= 0,h = arr[n-1]-arr[0];
    int mid = -1;
    while((h-l)>1) {
        debug(make_pair(l,h));
        mid = l+(h-l)/2;
        debug(mid);
        if(check(arr,mid,c)) l = mid;
        else h = mid-1;
    }
    if(check(arr,h,c)) cout<<h<<nl;
    else cout<<l<<nl;
    // cout<<mid<<nl;
    return 0;

}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    fast_io;
	auto start1 = high_resolution_clock::now();
    //----------------------------------------------
    int t=1;
    cin>>t;
    while(t--) {
        solve();

        
        // cout<<(solve() ? "YES" : "NO")<<nl;
    }
    //----------------------------------------------
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);

    #ifndef ONLINE_JUDGE
	    cerr << "Time: " << duration . count() / 1000 << endl;
    #endif

    return 0;
}