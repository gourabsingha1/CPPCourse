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

void printBinary(ll n){
    for (int i = 10; i >= 0; i--)
    {
        cout<<((n >> i) & 1);
    }
    cout<<endl;
}

int main(){
    // Bit Masking
    /*
    4 fruits
    0 = banana, 1 = apple, 2 = orange, 3 = grape
    3 person
    a = 2,3
    b = 0,1,3
    c = 1,3
    intersection(a,b) = 3 = O(N)
    a = 1100
    b = 1011
    a&b = 1000(3rd bit is set) = O(1)
    */

    /* Consider this problem: There are N≤5000 workers. Each worker is available during some days of this month (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability. You need to assign an important project to two workers but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available.
    */
    ll n;
    cin>>n;
    vl masks(n,0);
    fo(i,0,n){
        ll num_workers;
        cin>>num_workers;
        ll mask = 0;
        fo(j,0,num_workers){
            ll day;
            cin>>day;
            mask = (mask | (1<<day)); // making binary and making days set
        }
        masks[i] = mask;
    }
    // fo(i,0,n){
    //     cou(masks[i])
    //     printBinary(masks[i]);
    // }
    ll max_days = 0, person1 = -1, person2 = -1;
    fo(i,0,n){
        fo(j,i+1,n){
            ll intersection = masks[i] & masks[j];
            ll common_days = __builtin_popcount(intersection);
            // max_days = max(max_days, common_days);
            if(common_days > max_days){
                max_days = common_days;
                person1 = i;
                person2 = j;
            }
        }
    }
    cout<<person1<<" "<<person2<<" "<<max_days<<endl;

    
    
    return 0;
}