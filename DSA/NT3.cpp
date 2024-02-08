#include <bits/stdc++.h>
using namespace std;
#define cin(a) int n; cin>>n; int a[n]; for(int i = 0; i < n; ++i) {cin>>a[i];}
#define cinv(v) int n; cin>>n; vector<int> v; for(int i=0; i<n; ++i){int xx; cin>>xx; v.push_back(xx);}
#define nl cout<<"\n";
#define co(a) {cout<<a<<' ';}
#define cou(a) {cout<<a<<"\n";}
#define lcou(v) {for(auto& x : v) co(x); nl}
#define ll long long

const int M = 1e9 + 7;
const int MAX_N = 500001;


// **** Binary Exponentiation - O(logN), O(1) ****
ll exp(ll x, ll n, ll m = M) {
    ll res = 1;
    while(n) {
        if(n & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}


// **** Binary Multiplication - O(logN), O(1) ****
ll binaryMul(ll x, ll n, ll m = M) {
    ll res = 0;
    while(n) {
        if(n & 1) {
            res = (res + x) % m;
        }
        x = (x + x) % m;
        n >>= 1;
    }
    return res;
}


// **** Large Exponentiation - O(logN * logN), O(1) ****
ll largeExp(ll x, ll n, ll m = M) {
    ll res = 1;
    while(n) {
        if(n & 1) {
            res = binaryMul(res, x);
        }
        x = binaryMul(x, x);
        n >>= 1;
    }
    return res;
}


// **** Chinese Remainder Theorem - O(NlogM), O(1) ****
ll CRT(vector<ll> a, vector<ll> m) {
    ll X = 0, M = 1, n = a.size();
    for (int i = 0; i < n; i++)
    {
        M *= m[i];
    }
    for (int i = 0; i < n; i++)
    {
        ll Mi = M / m[i], invM = exp(Mi, M - 2, M);
        X += (a[i] * Mi * invM) % M;
    }
    return X;
}


int main(){
    ll a = 234398784, b = 79987897;
    cou(exp(a, b))
    cou(largeExp(a, b))

    // print 50 ^ 64 ^ 32 % M, where a = 50, b = 64 ^ 32, M = prime
    // use ETF. shrink b using binaryExp then a ^ b % M
    a = 50, b = exp(64, 32, M - 1); // ETF of M = M - 1
    cou(exp(a, b))

    cou(CRT({2,3,2}, {3,5,7}))
    
    return 0;
}