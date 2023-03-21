#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define driver int main(){ ll testCases; cin>>testCases; while(testCases--){ G();}return 0;}
#define driver1 int main(){ ll testCases = 1; while(testCases--){ G();}return 0;}
#define vl vector<ll>
#define vpll vector<pair<ll, ll>>
#define mll map<ll,ll>
#define arrLimit(a) a, a+n
#define vecLimit(v) v.begin(), v.end()
#define vass(v,s) v.assign(vecLimit(s));
#define saa(a) sort(arrLimit(a));
#define sad(a) sort(arrLimit(a), greater<ll>());
#define sva(v) sort(vecLimit(v));
#define svd(v) sort(v.rbegin(), v.rend());
#define suma(a) accumulate(arrLimit(a), 0);
#define sumv(v) accumulate(vecLimit(v), 0);
#define fo(i,j,n) for(ll i = j; i < n; ++i)
#define rfo(i,j,n) for(ll i = n - 1; i >= j; --i)
#define cin(a) ll n; cin>>n; ll a[n]; fo(i,0,n){cin>>a[i];}
#define cinv(v) ll n; cin>>n; vl v; fo(i,0,n){ll xx; cin>>xx; v.push_back(xx);}
#define nl cout<<"\n";
#define co(a) {cout<<a<<" ";}
#define cou(a) {cout<<a<<"\n";}
#define lcou(v) {for(auto &x : v) cout<<x<<" "; nl}
#define cy(x) {if(x) cou("YES") else cou("NO")}
int M = 1e9 + 7;


// **** Maximum / Mininum / Summation ****
int maxIndex(vector<int> &nums){
    return max_element(begin(nums), end(nums)) - begin(nums);
}
int maxElement(vector<int> &nums){
    return *max_element(nums.begin(), nums.end());
}
int sumVector(vector<int> &nums){
    return accumulate(nums.begin(), nums.end(), 0);
}


// **** Binary to Decimal ****
int binToDec(string& s){
    int n = s.size(), cnt = 0, res = 0;
    while(n--){
        res += (s[n] == '1') * (1 << cnt);
        cnt++;
    }
    return res;
}


// **** Decimal to Binary ****
string decToBin(int n){
    string res;
    while(n){
        if(n & 1) res = '1' + res;
        else res = '0' + res;
        n /= 2;
    }
    return res;
}


// **** Prime or not - O(sqrt(N)) ****
bool isPrime(int n){
    if(n <= 1) return 0;
    int sq = sqrt(n);
    for (int i = 2; i <= sq; i++)
    {
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

// **** Sieve of erathones - O(Nlog(logN)) ****
vector<ll> sieve(int n){
    vector<bool> Sieve(n+1);
    vector<ll> vSieve;
    for(int i = 2; i <= n; i++){
        if(!Sieve[i]){
            vSieve.push_back(i);
            for (int j = i * i; j <= n; j += i){
                Sieve[j] = 1;
            }
        }
    }
    return vSieve;
}


// **** No. of Divisors - O(sqrt(N)) ****
ll divCount(ll n){
    ll res = 0, sq = sqrt(n);
    for (int i = 1; i <= sq; i++)
    {
        if(n % i == 0){
            res += 2;
            if(n / i == i){
                res--;
            }
        }
    }
    return res;
}


// **** All Divisors - O(sqrt(N)) ****
vector<ll> divisors(ll n){
    vector<ll> res;
    int sq = sqrt(n);
    for (int i = 1; i <= sq; i++)
    {
        if(n % i == 0){
            res.push_back(i);
            if(n / i != i){
                res.push_back(n / i);
            }
        }
    }
    return res;
}


// **** pow(x,n) - O(log(N)) ****
ll exp(ll x, ll n, ll m = M){
    ll res = 1;
    while(n){
        if(n & 1) res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}


// **** logb(a) - O(log(N)) ****
ll logba(ll b, ll a) {
    ll res = 0;
    while(a > 1) {
        res++, a /= b;
    }
    if(pow(b, res) != a) res++;
    return res;
}

// **** Modulo operations ****
ll mod_add(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (mod_mul(a, exp(b, m - 2, m), m) + m) % m;}


// **** Modulo Inverse ****
int inv(int i, int m = 1e9 + 7) {
    return i <= 1 ? i : m - (long long)(m / i) * inv(m % i) % m;
}


// **** Palindrome or not ****
bool isPal(string s, ll start, ll end){
    while(start <= end){
        if(s[start++] != s[end--]){
            return 0;
        }
    }
    return 1;
}


// **** Find factorial ****
ll fac(ll n, int m = M){
    ll res = 1;
    while(n){
        res = (res * n) % m;
        n--;
    }
    return res;
}


// **** nCr ****
int nCr(int n, int r, int m = M){
    long res = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; i++)
    {
        res = (res * (n - r + i) / i) % m;
    }
    return res;
}


// **** Binary search- O(logN) ****
int binarySearch(vector<int> &nums, int key){
    int low = 0, high = nums.size() - 1; // 0 indexed
    while (low <= high)
    {
        int mid = high + (low - high) / 2;
        if (nums[mid] == key){
            return mid;
        }
        else if (nums[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return 0;
}


// **** Fibonacchi- O(N) ****
int fib(int n){
    int one = 0, two = 1;
    for(int i = 2; i < n; i++){
        int temp = two;
        two += one;
        one = temp;
    }
    return two;
}


// **** Hash value ****
int hash(string s, int p = M){
    int res = 0, n = s.size();
    for (int i = 0; i < n; i++)
    {
        res = mod_add(res, mod_mul(s[n - 1 - i] - 'a' + 1, exp(26, i, p), p), p);
    }
    return res;
}


// **** LPS ****
vector<int> lps(string &s) {
    int n = s.size(), i = 1, prevLPS = 0;
    vector<int> LPS(n, 0);
    while(i < n){
        if(s[i] == s[prevLPS]){
            LPS[i] = prevLPS + 1;
            prevLPS++, i++;
        }
        else if(prevLPS == 0){
            LPS[i] = 0, i++;
        }
        else{
            prevLPS = LPS[prevLPS - 1];
        }
    }
    return LPS;
}

// **** Newtons Table ****
void newtonsTable(){
    int n; cin>>n;
    int m = n + 1;
    vector<int> x(n), y(m);
    for (int i = 0; i < n; i++) cin>>x[i];
    for (int i = 0; i < n; i++) cin>>y[i];
    vector<vector<int>> res(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++){
        res[i][0] = x[i];
        res[i][1] = y[i];
    }
    for (int i = 2; i < m; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            res[j][i] = res[j + 1][i - 1] - res[j][i - 1];
        }
    }
    for(auto &v : res){
        for(auto &x : v){
            cout<<x<<' ';
        }
        cout<<"\n";
    }
}


// **** Sort by STL ****
static bool sortbysecasce(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
static bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b){
    return a.second > b.second;
}
static bool sortbyvector(const vector<int> &a, const vector<int> &b){
    return a[1] < b[1];
}
// sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) -> bool{return a[1] < b[1];});


void G(void){
    // newtonsTable();
    cout<<decToBin(25);
}

driver1