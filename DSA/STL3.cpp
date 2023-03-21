#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvs vector<vs>
#define pb(a) push_back(a);
#define saa(a) sort(a,a+n);
#define sad(a) sort(a,a+n, greater<ll>());
#define sva(v) sort(v.begin(), v.end());
#define svd(v) sort(v.begin(), v.end(), greater<ll>());
#define mia(m,a) ll m = *min_element(a,a+n);
#define maa(m,a) ll m = *max_element(a,a+n);
#define miv(m,v) ll m = *min_element(v.begin(), v.end());
#define mav(m,v) ll m = *max_element(v.begin(), v.end());
#define fo(i,j,n) for(int i = j; i < n; ++i)
#define foe(i,j,n) for(int i = j; i <= n; ++i)
#define rfo(i,j,n) for(int i = n - 1; i >= j; --i)
#define rfoe(i,j,n) for(int i = n; i >= j; --i)
#define cin(a) ll n; cin>>n; ll a[n]; fo(i,0,n){cin>>a[i];}
#define nl cout<<endl;
#define co(a) {cout<<a<<" ";}
#define cou(a) {cout<<a<<" "; nl;}
#define lcou(a) {for(auto &x:a) cout<<x<<" "; nl;}
ll M = 1e9+7;

int main(){

    // **** Lower bound and upper bound ****
    cin(a)
    saa(a)
    ll *ptr1 = lower_bound(a,a+n,5); // If present, return element
    // ll *ptr1 = lower_bound(a+4,a+n,5);
    ll *ptr2 = upper_bound(a,a+n,5); // If present, strictly next bigger element
    if(ptr1==(a+n)){
        cou("Not found")
    }
    else{
        cou("Lowerbound is: "<<*ptr1)
    }
    if(ptr2==(a+n)){
        cou("Not found")
    }
    else{
        cou("Upperbound is: "<<*ptr2)
    }
    set<ll>s;
    fo(i,0,4){
        ll x; cin>>x;
        s.insert(x);
    }
    auto it = s.lower_bound(5);
    cou(*it)
    
    return 0;
}