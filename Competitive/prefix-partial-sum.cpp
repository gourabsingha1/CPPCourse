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


    // **** Partial sum ****
    // cou("-Partial sum") // +LRX -> Add x to all the index in the range L to R
    // ll n1,q1;
    // cin>>n1>>q1;
    // ll a1[n1]={};
    // fo(i,0,q1){
    //     ll l,r,x;
    //     cin>>l>>r>>x;
    //     a1[l]+=x;
    //     a1[r+1]-=x;
    // }
    // ll s1 = a1[0];
    // co(s1)
    // fo(i,1,n1){
    //     s1+=a1[i];
    //     co(s1)
    // }nl
    // nl



    // **** AP on Prefix sum ****
    // cou("-AP on Prefix sum") // a[l]+a[l+1]*2+a[l+2]*3+...+a[r]*[r-l+1]
    // ll n2,q2;
    // cin>>n2>>q2;
    // ll a2[n2];
    // fo(i,0,n2){
    //     cin>>a2[i];
    // }
    // fo(i,0,q2){
    //     ll l,r;
    //     cin>>l>>r;
    //     ll s2 = 0;
    //     // E(l to r) a2[i]*(i-l+1) -> E(l to r)a2[i]*i + (1-l)*E(l to r) a2[i]
    //     foe(i,l,r){
    //         s2+=a2[i]*i+(1-l)*a2[i];
    //     }
    //     cou(s2)
    // }
    // nl


    
    // **** GP on Prefix sum ****
    // cou("-GP on Prefix sum") // a[l]+a[l+1]*k+a[l+2]*k^2+...+a[r]*k^[r-l]



    return 0;
}