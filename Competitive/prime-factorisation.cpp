#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
#define mia(m,a) ll m = *min_element(a,a+n);
#define maa(m,a) ll m = *max_element(a,a+n);
#define miv(m,v) ll m = *min_element(v.begin(), v.end());
#define mav(m,v) ll m = *max_element(v.begin(), v.end());
#define fo(i,j,n) for(int i = j; i < n; ++i)
#define foe(i,j,n) for(int i = j; i <= n; ++i)
#define rfo(i,j,n) for(int i = n - 1; i >= j; --i)
#define rfoe(i,j,n) for(int i = n; i >= j; --i)
#define cina ll n; cin>>n; ll a[n]; fo(i,0,n){cin>>a[i];}
#define nl cout<<endl;
#define co(a) {cout<<a<<" ";}
#define cou(a) {cout<<a<<" "; nl;}
#define lcou(a) {for(auto &x:a) cout<<x<<" "; nl;}
ll M = 1e9+7;

const int N = 1e7+10;
vector<bool>isPrime(N,1);
vl lp(N,0), hp(N,0); // lowest prime and highest prime

int main(){

    // **** O(sqrt(n)) ****
    // ll n;
    // cin>>n;
    // vl prime_factors;
    // foe(i,2,sqrt(n)){
    //     while(n%i==0){
    //         prime_factors.pb(i);
    //         n/=i;
    //     }
    // }
    // if(n>1){
    //     prime_factors.pb(n)
    // }
    // lcou(prime_factors)

    // **** O(n*log(log(n))) ****
    isPrime[0] = isPrime[1] = false;
    fo(i,2,N){
        if(isPrime[i]==true){
            lp[i] = hp[i] = i;
            for(int j = 2*i; j<N; j+=i){
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j]==0){
                    lp[j]=i;
                }
            }
        }
    }
    ll q;
    cin>>q;
    while(q--){
        ll num;
        cin>>num;
        vl prime_factors; // num
        // unordered_map<int,int>prime_factors; // num power

        if(isPrime[num]){
            cou("Prime")
        }
        else{
            cou("Not Prime")
        }

        // co(lp[num]) cou(hp[num])

        while(num>1){
            ll prime_factor = hp[num];
            while(num%prime_factor==0){
                num/=prime_factor;
                prime_factors.pb(prime_factor);
                // prime_factors[prime_factor]++;
            }
        }
        rfo(i,0,prime_factors.size()){
            co(prime_factors[i])
        }
        nl
    //     for(auto x : prime_factors){
    //         co(x.first) cou(x.second)
    //     }
    }
    
    return 0;
}