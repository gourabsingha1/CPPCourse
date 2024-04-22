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




// 1. count no. of numbers in [l, r] whose digit sum is a prime number
class digitDpPrime {
public:
    ll dp[20][2][200];

    // check if the sum of digits is prime
    bool check(ll sum) {
        return isPrime(sum);
    }

    ll helper(string& s, int pos = 0, bool tight = 1, ll sum = 0) {
        if(pos == s.size()) {
            return check(sum);
        }
        if(dp[pos][tight][sum] != -1) {
            return dp[pos][tight][sum];
        }

        ll res = 0;
        if(tight == 1) {
            for (int i = 0; i <= s[pos] - '0'; i++)
            {
                if(i == s[pos] - '0') {
                    res += helper(s, pos + 1, 1, sum + i);
                }
                else {
                    res += helper(s, pos + 1, 0, sum + i);
                }
            }
        }
        else {
            for (int i = 0; i <= 9; i++)
            {
                res += helper(s, pos + 1, 0, sum + i);
            }
        }
        return dp[pos][tight][sum] = res;
    }

    ll solve(ll l, ll r) {
        l--;
        string a = to_string(l), b = to_string(r);
        memset(dp, -1, sizeof(dp));
        ll res1 = helper(a); // from 1 to l
        memset(dp, -1, sizeof(dp));
        ll res2 = helper(b); // from 1 to r
        return res2 - res1;
    }
};


// 2. count no. of numbers in [l, r] where a given digit is occuring
class countGivenDigit {
public:
    ll dp[20][2][2];

    // flag = 1 means givenDigit is present in the number
    ll helper(string& s, int& givenDigit, int pos = 0, bool tight = 1, bool flag = 0) {
        if(pos == s.size()) {
            return flag;
        }
        if(dp[pos][tight][flag] != -1) {
            return dp[pos][tight][flag];
        }

        ll res = 0, ub = tight ? s[pos] - '0' : 9;
        for (int i = 0; i <= ub; i++)
        {
            if(pos == 0 && i == 0) { // leading zero
                res += helper(s, givenDigit, pos + 1, tight & (i == ub), flag);
                continue;
            }
            res += helper(s, givenDigit, pos + 1, tight & (i == ub), flag | (i == givenDigit));
        }
        return dp[pos][tight][flag] = res;
    }

    ll solve(ll l, ll r, int givenDigit) {
        l--;
        string a = to_string(l), b = to_string(r);
        memset(dp, -1, sizeof(dp));
        ll res1 = helper(a, givenDigit); // from 1 to l
        memset(dp, -1, sizeof(dp));
        ll res2 = helper(b, givenDigit); // from 1 to r
        return res2 - res1;
    }
};

// 3. count no. of numbers made from digits in a set
// where number of digits = n
// and difference bw adjacent elements <= limit
class countSetLimit {
public:
    ll dp[20][10];

    ll helper(vector<int>& nums, int& n, int& limit, int pos = 0, int prev = 0) {
        if(pos == n) {
            return 1;
        }
        if(dp[pos][prev] != -1) {
            return dp[pos][prev];
        }

        ll res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(prev == 0 || abs(nums[i] - prev) <= limit) {
                res += helper(nums, n, limit, pos + 1, nums[i]);
            }
        }
        return dp[pos][prev] = res;
    }

    ll solve(vector<int> nums, int n, int limit) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, n, limit);
    }
};



int main() {
    // digitDpPrime ddp;
    // cout<<ddp.solve(10, 19)<<endl;
    // cout<<ddp.solve(1, 9)<<endl;
    // cout<<ddp.solve(20, 29)<<endl;

    
    countGivenDigit ddoogd;
    cout<<ddoogd.solve(1, 5, 3)<<endl;
    cout<<ddoogd.solve(1, 14, 3)<<endl;
    cout<<ddoogd.solve(1, 76, 3)<<endl;
    cout<<ddoogd.solve(1, 67, 3)<<endl;
    cout<<ddoogd.solve(1, 40, 3)<<endl;

    // countSetLimit csl;
    // cout<<csl.solve({1, 3, 6}, 2, 2)<<endl;
    // cout<<csl.solve({1, 2, 3}, 2, 2)<<endl;
    // cout<<csl.solve({1, 4, 6}, 3, 2)<<endl;
}