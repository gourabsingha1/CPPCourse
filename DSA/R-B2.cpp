#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define make make_pair
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vc vector<char>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvs vector<vs>
#define vvc vector<vc>
#define vpll vector<pair<ll,ll>>
#define vplll vector<pair<pair<ll,ll>,ll>>
#define mll map<ll,ll>
#define mcl map<char,ll>
#define pb(a) push_back(a);
#define saa(a) sort(a,a+n);
#define sad(a) sort(a,a+n, greater<ll>());
#define sva(v) sort(v.begin(), v.end());
#define svd(v) sort(v.rbegin(), v.rend());
#define mia(m,a) ll m = *min_element(a,a+n);
#define maa(m,a) ll m = *max_element(a,a+n);
#define suma(s,a) ll s = 0; s = accumulate(a,a+n,s);
#define miv(m,v) ll m = *min_element(v.begin(), v.end());
#define mav(m,v) ll m = *max_element(v.begin(), v.end());
#define fo(i,j,n) for(int i = j; i < n; ++i)
#define foe(i,j,n) for(int i = j; i <= n; ++i)
#define rfo(i,j,n) for(int i = n - 1; i >= j; --i)
#define rfoe(i,j,n) for(int i = n; i >= j; --i)
#define afo(v) for(auto &x : v)
#define cin(a) ll n; cin>>n; ll a[n]; fo(i,0,n){cin>>a[i];}
#define cinvl(v) ll n; cin>>n; vl v; fo(i,0,n){ll xx; cin>>xx; v.pb(xx)}
#define cinvs(v) ll n; cin>>n; vs v; fo(i,0,n){string xx; cin>>xx; v.pb(xx)}
#define nl cout<<endl;
#define co(a) {cout<<a<<" ";}
#define cou(a) {cout<<a<<" "; nl}
#define lcou(v) {afo(v) cout<<x<<" "; nl}
#define siz(v) v.size()
ll M = 1e9+7;


// **** Print all subsequences whose sum is K ****
void PSubK(ll i, vector<ll>&v, ll a[], ll n, ll k, ll s){
    if(i==n){
        if(s==k){
           for(auto x : v){
                co(x)
            }nl
        }
        return;
    }
    v.pb(a[i])
    s+=a[i];
    PSubK(i+1, v, a, n, k, s);
    v.pop_back();
    s-=a[i];
    PSubK(i+1, v, a, n, k, s);
}



// **** Print only one subsequence whose sum is K ****
bool PSubK1(ll i, vector<ll>&v, ll a[], ll n, ll k, ll s){
    if(i==n){
        if(s==k){
           for(auto x : v){
                co(x)
            }nl
            return true;
        }
        else{
            return false;
        }
    }
    v.pb(a[i])
    s+=a[i];
    if(PSubK1(i+1, v, a, n, k, s)==true){ // if true, no need to check further
        return true;
    }
    v.pop_back();
    s-=a[i];
    if(PSubK1(i+1, v, a, n, k, s)==true){
        return true;
    }
    return false; // if none of them is true
}



// **** Count the number of subsequences whose sum is K ****
ll PSubKC(ll i, ll a[], ll n, ll k, ll s){
    if(i==n){
        if(s==k){
            return 1;
        }
        else{
            return 0;
        }
    }
    s+=a[i];
    ll l = PSubKC(i+1, a, n, k, s); // if true, no need to check further
    s-=a[i];
    ll r = PSubKC(i+1, a, n, k, s);
    return l+r;
}



// **** Print all subsequences (Repeated) whose sum is K || Combination Sum ****
class CombinationSum{
public:
    void helper(int target, int currInd, vector<int>& candidates, vector<int> v, vector<vector<int>> &res){
        int n = candidates.size();
        if(target <= 0){
            if(!target) res.push_back(v);
            return;
        }
        for (int i = currInd; i < n; i++)
        {
            v.push_back(candidates[i]);
            target -= candidates[i];
            helper(target, i, candidates, v, res);
            v.pop_back();
            target += candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(target, 0, candidates, {}, res);
        return res;
    }
};



// **** Print all subsequences (Non Repeated) whose sum is K ****
class Sol2 {
    public:
        vvl PSubKNR(ll i, vl &v, vvl &ans, ll a[], ll n, ll k) {
            if(k==0) {
                ans.pb(v);
                return ans;
            }
            saa(a)
            fo(j,i,n){
                if(j>i && a[j]==a[j-1]){
                    continue; 
                }
                if(a[j]>k){
                    break; 
                }
                v.push_back(a[j]);
                PSubKNR(j+1, v, ans, a, n, k-a[j]); 
                v.pop_back(); 
            }
            return ans;
        }
    // cin(a)
    // ll k; cin>>k;
    // vl v;
    // vvl ans;
    // Sol2 s2;
    // for(auto x : s2.PSubKNR(0, v, ans, a, n, k)){
    //     lcou(x)
    // }
};



int main(){
    // vi v = {4, 12, 2, 18, 15, 3, 17};
    // int k = 6;
    // CombinationSum s1;
    // for(auto x : s1.combinationSum(v, k)){
    //     lcou(x)
    // }
    // Sol2 s2;
    // for(auto x : s2.PSubKNR(0, v, ans, a, n, k)){
    //     lcou(x)
    // }

    
    return 0;
}