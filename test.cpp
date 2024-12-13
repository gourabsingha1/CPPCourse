#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define int long long
#define vl vector<int>
#define vpll vector<pair<int, int>>
#define mll map<int, int>
#define all(v) v.begin(), v.end()
#define cin(a) int n; cin>>n; vector<int> a(n); for (int i = 0; i < n; i++) {cin>>a[i];}
#define cina(b, n) vector<int> b(n); for (int i = 0; i < n; i++) {cin>>b[i];}
#define nl cout<<"\n";
#define co(a) {cout<<a<<' ';}
#define cou(a) {cout<<a<<"\n";}
#define lcou(v) {for(auto& x : v) co(x); nl}
#define cy(x) {if(x) cou("YES") else cou("NO")}

const int M = 1e9 + 7;
const int MAX_N = 500001;

static bool sortbysecdesc(const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;}
static bool cmp(const vector<int>& a, const vector<int>& b) {return a[1] < b[1];}
int exp(int x, int n, int m = M) {int res = 1; while(n) {if(n & 1) res = (res * x) % m; x = (x * x) % m; n >>= 1;} return res;}
int logba(int b, int a) {int res = 0; while(a > 1) res++, a /= b; if(pow(b, res) != a) res++; return res;}
int fac(int n, int m = M) {int res = 1; while(n) {res = (res * n) % m; n--;} return res;}
int divCount(int n) {int res = 0; for (int i = 1; i * i <= n; i++) {if(n % i == 0) {res += 2; if(n / i == i) res--;}} return res;}
bool isPrime(int n) {if(n <= 1) return 0; for (int i = 2; i * i <= n; i++) {if(n % i == 0) return 0;} return 1;}
int mod_add(int a, int b, int m = M) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m = M) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m = M) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m = M) {a = a % m; b = b % m; return (mod_mul(a, exp(b, m - 2, m), m) + m) % m;}
int mod_inv(int a, int m = M) { return exp(a, m - 2, m);}



void G() {
    
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    
    
    int TC = 1;
    cin>>TC;
    while(TC--) {
        G();
    }
    return 0;
}