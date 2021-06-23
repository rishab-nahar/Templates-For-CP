#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> p32;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
const ll MOD = 1e9 +7;
const ll MOD2= 998244353;
double eps = 1e-12;
#define endl           "\n"
#define fori(e) for(ll i = 0; i < e; i++)
#define forj(e) for(ll j = 0; j < e; j++)
#define fork(e) for(ll k = 0; k < e; k++)
#define forri(e) for(ll i = e; i >= 0; i--)
#define forrj(e) for(ll j = e; j >= 0; j--)
#define forrk(e) for(ll k = e; k >= 0; k--)
#define forsi(s,e) for(ll i = s; i < e; i++)
#define forsj(s,e) for(ll j = s; j < e; j++)
#define forsk(s,e) for(ll k = s; k < e; k++)
#define forn(k,e) for(ll k = 0; k < e; k++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define forx(v) for(auto x:v)
#define gcd             __gcd
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define maxe           *max_element
#define mine           *min_element
#define deci(x, y)     fixed<<setprecision(y)<<x
#define ln endl
#define dbg1(x) cout<<#x<<" = "<<x<<endl
#define dbg2(x,y) cout<<#x<<" = "<<x<<endl<<#y<<" = "<<y<<endl
#define dbg3(x,y,z) cout<<#x<<" = "<<x<<endl<<#y<<" = "<<y<<endl<<#z<<" = "<<z<<endl
//#define mp make_pair
#define append push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define mem0(x)        memset(x,0,sizeof x)
#define mem1(x)        memset(x,-1,sizeof x)

using namespace std;


template <typename T>
void get_ar(T *ar, ll n)
{
    fori(n) cin>>ar[i];
}
template <typename T>
void printar(T *ar, ll n)
{
    fori(n) cout<<ar[i]<<" ";
    cout<<endl;
}


ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll imod(ll a, ll m)
{
    return power(a, m - 2, m);
}


template< typename T, size_t N, size_t M >
void print2dArray( T(&theArray)[N][M]  ,ll n=N, ll m=M) {
    for ( ll x = 0; x < n; x ++ ) {
        for ( ll y = 0; y < m; y++ ) {
            cout << theArray[x][y] << " ";
        }
        cout<<endl;
    }
}


template< typename T, size_t N >
void print_ar( T(&theArray)[N]  ,ll n=N) {
    for ( ll x = 0; x < n; x ++ )
    {
        cout << theArray[x] << " ";
    }
        cout<<endl;
    }







void solve(){
    ll n,K,ans=0,tmp;




}
int main()
{
    fast_cin();
    ll t=1;
//    cin >> t;
    for(ll it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
