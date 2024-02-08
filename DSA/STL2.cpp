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
    
    // **** Nesting in Maps and Sets ****
    map<pair<string,string>,vector<ll>> mNest;
    string fn, ln;
    ll ct;
    cou("Enter first name, last name and the number of ct: ")
    cin>>fn>>ln>>ct;
    fo(i,0,ct){
        ll x;
        cin>>x;
        mNest[{fn,ln}].pb(x);
    }
    for(auto &pr : mNest){
        auto &first_name = pr.first.first;
        auto &last_name = pr.first.second;
        auto &ctVec = pr.second;
        co("The first name is:") cou(first_name) co("The last name is:") cou(last_name)
        cou(ctVec.size())
        cou(ctVec[ctVec.size()-1])
    }

    cou("Q1. Given students' names and marks, output according to decreasing marks. If marks are same, then lexographical order of names.")
    map<ll,multiset<string>> mMarks; // duplicate elements will be printed
    fo(i,0,4){
        string name;
        ll mark;
        cou("Enter student name and mark:")
        cin>>name>>mark;
        mMarks[mark].insert(name);
        // mMarks[-1*mark].insert(name);
    }
    auto last_it = --mMarks.end(); // starting from highest mark
    while(true){
        auto &students = (*last_it).second;
        ll mark = (*last_it).first;
        for(auto s : students){
            co(s) cou(mark)
        }
        if(last_it==mMarks.begin()){
            break;
        }
        last_it--;
    }
    
    return 0;
}