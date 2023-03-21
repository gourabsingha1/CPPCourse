#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define tc(a) ll TC; cin >> TC; while(TC--){a}
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvs vector<vs>
#define si stack<int>
#define sl stack<ll>
#define ss stack<string>
#define pb(a) push_back(a);
#define saa(a) sort(a,a+n);
#define sad(a) sort(a,a+n, greater<ll>());
#define sva(v) sort(v.begin(), v.end());
#define svd(v) sort(v.begin(), v.end(), greater<ll>());
#define fo(i,j,n) for(int i = j; i < n; i++)
#define foe(i,j,n) for(int i = j; i <= n; i++)
#define rfo(i,j,n) for(int i = n - 1; i >= j; i--)
#define rfoe(i,j,n) for(int i = n; i >= j; i--)
#define cina ll n; cin>>n; ll a[n]; fo(i,0,n){cin>>a[i];}
#define nl cout<<endl;
#define co(a) {cout<<a<<" ";}
#define cou(a) {cout<<a<<" "; nl;}
#define lcou(a) {for(auto x:a) cout<<x<<" "; nl;}
ll M = 1e9+7;

/* Binary Exponentiation */
// Recursive Method
int binExpRecur(ll a, ll b){
    if(b==0){
        return 1;
    }
    ll res = binExpRecur(a,b/2);
    if(b&1!=0){
        return (a*((res*res)%M))%M;
    }
    else{
        return (res*res)%M;
    }
}

// Iterative Method (TC = log^2(N))
int binExpIter(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = binMultiply(ans,a) % M;
        }
        a = binMultiply(a,a) % M;
        b = b >> 1;
    }
    return ans;
}

// for multiplication of long long datatypes
int binMultiply(ll a, ll b){
    ll ans = 0;
    while(b>0){
        if(b&1){
            ans = (ans+a) % M;
        }
        a = (a+a) % M;
        b = b >> 1;
    }
    return ans;
}

int main(){
    ll a = 23434, b = 7;
    cou(binExpRecur(a,b))
    cou(binExpIter(a,b))
    
    return 0;
}