#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vpll vector<pair<ll, ll>>
#define mll map<ll, ll>
#define all(v) v.begin(), v.end()
#define cin(v) ll n; cin>>n; vector<ll> v(n); for (ll i = 0; i < n; i++) {cin>>v[i];}
#define nl cout<<"\n";
#define co(a) {cout<<a<<' ';}
#define cou(a) {cout<<a<<"\n";}
#define lcou(v) {for(auto& x : v) co(x); nl}
#define cy(x) {if(x) cou("ODD") else cou("EVEN")}

const int M = 1e9 + 7;
const int MAX_N = 500001;

static bool sortbysecasce(const pair<ll, ll>& a, const pair<ll, ll>& b) {return a.second < b.second;}
static bool sortbysecdesc(const pair<ll, ll>& a, const pair<ll, ll>& b) {return a.second > b.second;}
static bool cmp(const vector<ll>& a, const vector<ll>& b) {return a[1] < b[1];}
ll exp(ll x, ll n, ll m = M) {ll res = 1; while(n) {if(n & 1) res = (res * x) % m; x = (x * x) % m; n >>= 1;} return res;}
ll logba(ll b, ll a) {ll res = 0; while(a > 1) res++, a /= b; if(pow(b, res) != a) res++; return res;}
ll fac(ll n, ll m = M) {ll res = 1; while(n) {res = (res * n) % m; n--;} return res;}
ll divCount(ll n) {ll res = 0; for (int i = 1; i * i <= n; i++) {if(n % i == 0) {res += 2; if(n / i == i) res--;}} return res;}
bool isPrime(ll n) {if(n <= 1) return 0; for (int i = 2; i * i <= n; i++) {if(n % i == 0) return 0;} return 1;}
ll mod_add(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (mod_mul(a, exp(b, m - 2, m), m) + m) % m;}
ll mod_inv(ll a, ll m = M) { return exp(a, m - 2, m);}



void G() {
    ll n;
    cin>>n;
    cy(__builtin_popcount(n) % 2)
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll TC = 1;
    cin>>TC;
    while(TC--) {
        G();
    }
    return 0;
}