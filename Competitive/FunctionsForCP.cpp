#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vpll vector<pair<ll, ll>>
#define mll map<ll, ll>
#define all(v) v.begin(), v.end()
#define cin(a) ll n; cin>>n; ll a[n]; for (int i = 0; i < n; i++) {cin>>a[i];}
#define cinv(v) ll n; cin>>n; vector<ll> v(n); for (int i = 0; i < n; i++) {cin>>v[i];}
#define nl cout<<"\n";
#define co(a) {cout<<a<<' ';}
#define cou(a) {cout<<a<<"\n";}
#define lcou(v) {for(auto& x : v) co(x); nl}
#define cy(x) {if(x) cou("YES") else cou("NO")}

const int M = 1e9 + 7;
const int MAX_N = 500001;

static bool sortbysecasce(const pair<ll, ll>& a, const pair<ll, ll>& b) {return a.second < b.second;}
static bool sortbysecdesc(const pair<ll, ll>& a, const pair<ll, ll>& b) {return a.second > b.second;}
static bool cmp(const vector<ll>& a, const vector<ll>& b) {return a[1] < b[1];}
ll exp(ll x, ll n, ll m) {ll res = 1; while(n) {if(n & 1) res = (res * x) % m; x = (x * x) % m; n >>= 1;} return res;}
ll logba(ll b, ll a) {ll res = 0; while(a > 1) res++, a /= b; if(pow(b, res) != a) res++; return res;}
ll fac(ll n, ll m = M) {ll res = 1; while(n) {res = (res * n) % m; n--;} return res;}
ll divCount(ll n) {ll res = 0; for (int i = 1; i * i <= n; i++) {if(n % i == 0) {res += 2; if(n / i == i) res--;}} return res;}
bool isPrime(ll n) {if(n <= 1) return 0; for (int i = 2; i * i <= n; i++) {if(n % i == 0) return 0;} return 1;}
ll mod_add(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (mod_mul(a, exp(b, m - 2, m), m) + m) % m;}
ll mod_inv(ll a, ll m = M) { return exp(a, m - 2, m);}


// **** Sieve of Eratosthenes - O(Nlog(logN)), O(N) ****
vector<bool> sieveIsPrime(MAX_N, 1);
vector<int> lp(MAX_N, 0), hp(MAX_N, 0); // lowest and highest prime
void sieve_init(int n) {
    sieveIsPrime[0] = sieveIsPrime[1] = 0;
    for (int i = 2; i < n; i++) {
        if(sieveIsPrime[i]) {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < n; j += i) {
                sieveIsPrime[j] = 0;

                if(lp[j] == 0) {
                    lp[j] = i;
                }
                hp[j] = i;
            }
        }
    }
}


// **** Prime Factorization - O(logN), O(sqrt(N)) ****
vector<int> primeFactors(int num) {
    vector<int> res;
    while(num > 1) {
        int primeFactor = hp[num];
        while(num % primeFactor == 0) {
            num /= primeFactor;
            res.push_back(primeFactor);
        }
    }
    return res;
}


// **** Divisors and their Sums - O(NlogN), O(sqrt(N)) ****
vector<int> divisors[MAX_N];
vector<int> divisorsSum(MAX_N, 0);
void divisors_init(int n) {
    for (int i = 2; i < n; i++) {
        for (int j = i; j < n; j += i) {
            divisors[j].push_back(i);
            divisorsSum[j] += i;
        }
    }
}


// **** Factorial and nCr - O(N), O(N) ****
int fact[MAX_N], ifact[MAX_N];

void fact_init() {
    fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % M;
        ifact[i] = mod_inv(fact[i]);
    }
}

ll nCr(int n, int r) {
    if (n < r || r < 0) return 0;
    return (((fact[n] * ifact[r]) % M) * ifact[n - r]) % M;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    sieve_init(MAX_N);
    divisors_init(MAX_N);
    
    ll TC = 1;
    cin>>TC;
    while(TC--) {
        ll n;
        cin>>n;
        co(sieveIsPrime[n]) co(lp[n]) cou(hp[n])
        lcou(primeFactors(n))
        lcou(divisors[n])
        nl
    }
    return 0;
}




















// **** Geometry - O(1), O(1) ****

// check if square
ll getDisSquare(ll x1, ll y1, ll x2, ll y2){
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool isSquareHelper(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	ll d1, d2, d3, d4, d5, d6;
	d1 = getDisSquare(x1, y1, x2, y2);
	d2 = getDisSquare(x2, y2, x3, y3);
	d3 = getDisSquare(x3, y3, x4, y4);
	d4 = getDisSquare(x4, y4, x1, y1);
	if(d1 == d2 && d1 == d3 && d1 == d4) { 
		d5 = getDisSquare(x1, y1, x3, y3);
		d6 = getDisSquare(x2, y2, x4, y4);
        return d5 == d6;
	}
	return 0;
}

bool isSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    return isSquareHelper(x1, y1, x2, y2, x3, y3, x4, y4) || isSquareHelper(x1, y1, x2, y2, x4, y4, x3, y3) || isSquareHelper(x1, y1, x3, y3, x2, y2, x4, y4);
}

// check if two sides are equal
bool isEqualateralTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
	int d1 = getDisSquare(x1, y1, x2, y2);
	int d2 = getDisSquare(x2, y2, x3, y3);
	int d3 = getDisSquare(x3, y3, x1, y1);
	return d1 == d2 && d1 == d3;
}

// check if first point is right angle
bool isRightAngleTriangleHelper(int x1, int y1, int x2, int y2, int x3, int y3){
	int d1 = getDisSquare(x1, y1, x2, y2);
	int d2 = getDisSquare(x2, y2, x3, y3);
	int d3 = getDisSquare(x3, y3, x1, y1);
	return d2 == d1 + d3;
}

bool isRightAngleTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
	return isRightAngleTriangleHelper(x1, y1, x2, y2, x3, y3) || isRightAngleTriangleHelper(x2, y2, x3, y3, x1, y1) || isRightAngleTriangleHelper(x3, y3, x1, y1, x2, y2);
}

// check if slope is same
bool areCollinear(int x1, int y1, int x2, int y2, int x3, int y3){
	return (x3 - x1) * (y2 - y1) == (y3 - y1) * (x2 - x1);
}