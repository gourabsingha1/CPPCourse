#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(a) push_back(a);
#define vl vector<ll>
#define vvl vector<vl>
#define fo(i,j,n) for(int i = j; i < n; ++i)
#define cin(a) int n; cin>>n; int a[n]; fo(i,0,n){cin>>a[i];}
#define nl cout<<endl;
#define co(a) {cout<<a<<" ";}
#define cou(a) {cout<<a<<" "; nl}
#define lcou(v) {afo(v) cout<<x<<" "; nl}


// **** sum of 1 to N ****
ll FSum(ll n){
    if(n==0){
        return 0;
    }
    return n + FSum(n-1);
}



// **** Reverse an array ****
void FArr(ll i, ll n, ll a[]){
    if(i==n){
        return;
    }
    FArr(i+1, n, a);
    co(a[i])
}
void FArr2(ll i, ll n, ll a[]){
    if(i>=n/2){
        return;
    }
    swap(a[i], a[n-i+1]);
    FArr2(i+1, n, a);
}



// **** Check palindrome ****
bool FPal(ll i, string &s){
    if(i>=s.size()/2){
        return true;
    }
    if(s[i]!=s[s.size()-1-i]){
        return false;
    }
    return FPal(i+1, s);
}



// **** Print all subsequences ****
void PSub(int i, vector<int>&v, int a[], int n){
    if(i==n){
        for(auto x : v){
            cout<<x<<" ";
        }
        if(v.size()==0){
            cout<<"{} ";
        }
        cout<<endl;
        return;
    }
    v.push_back(a[i]);
    PSub(i+1, v, a, n); // pick
    v.pop_back();
    PSub(i+1, v, a, n); // not pick
}



// **** Get stairs path **** https://www.youtube.com/watch?v=hMJAlbJIS7E&list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs&index=29
vector<string> getStairsPath(int n){
    if(n == 0){
        return {""};
    }
    else if(n < 0){
        return {};
    }
    vector<string> paths1 = getStairsPath(n-1);
    vector<string> paths2 = getStairsPath(n-2);
    vector<string> paths3 = getStairsPath(n-3);
    vector<string> resPaths;
    for(string &path : paths1){
        resPaths.push_back('1' + path);
    }
    for(string &path : paths2){
        resPaths.push_back('2' + path);
    }
    for(string &path : paths3){
        resPaths.push_back('3' + path);
    }
    return resPaths;
}



int main(){
    for(auto &path : getStairsPath(10)){
        cout<<path<<endl;
    }
    
    return 0;
}