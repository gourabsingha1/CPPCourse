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
    
    // **** bit manipulation ****

    ll a = 9;
    printBinary(9);

    // check if ith bit is set or unset
    ll i = 4;
    if(a & (1 << i)) {
        cout<<"set bit"<<endl;
    }
    else{
        cout<<"unset bit"<<endl;
    }

    // make the ith bit set bit
    a = a | (1 << i);
    printBinary(a);

    // make the ith bit unset bit
    a = a & (~(1<<i)); // ~ inverts the binary
    printBinary(a);

    // toggle the ith bit (1->0 or 0->1)
    a = a ^ (1<<i);
    printBinary(a);

    // count setbits
    cout<< __builtin_popcount(a)<<endl; // int
    cout<< __builtin_popcountll((1LL<<35) - 1)<<endl; // ll

    // check odd/even
    if(a&1!=0){
        cout<<"odd"<<endl;
    }
    else{
        cout<<"even"<<endl;
    }

    //divide by 2 (faster way)
    cout<<(a>>1)<<endl; // a = 11001. after-> 1100

    //multiply by 2 (faster way)
    cout<<(a<<1)<<endl; // a = 11001. after-> 110010

    // difference bw uppercase and lowercase = 5th bit is set in lowercase

    // uppercase to lowercase
    char p = 'A';
    // char q = p | (1<<5);
    char q = p | ' '; // 1<<5 is the ASCII value of space
    cout<<q<<endl;

    // lowercase to uppercase
    char r = 'a';
    // cout<<char(r & (~(1<<5)))<<endl;
    cout<<char(r & ('_'))<<endl; // binary of _ is 00001011111 (5th bit is unset)
    
    // clear LSB
    ll s = 59;
    printBinary(59);
    ll j = 4; // starting from the jth bit, clear LSB (unset bits)
    ll b = (s & ~( (1<<(j+1)) - 1) );
    printBinary(b);

    // clear MSB
    ll k = 3; // starting from the kth bit, clear MSB (unset bits)
    ll c = (s & ((1<<(k+1)) - 1));
    printBinary(c);

    // check power of 2
    ll n = 16;
    if(n & (n-1)){
        cout<<"not power of 2"<<endl;
    }
    else{
        cout<<"power of 2"<<endl;
    }

    // properties of xor
    // x^x = 0
    // x^0 = x
    // x^(x^y) = y

    // swap two numbers using xor
    ll x = 4, y = 6;
    x = x^y;
    y = y^x; // y = y^(x^y) = y^y^x = x
    x = x^y; // x = (x^y)^x = x^x^y = y
    cout<<x<<" "<<y<<endl;

    /* Given an array arr of n integers. All integers are present in event count except one. Find that one integer which has odd count in O(N) time complexity and O(1) space
    N < 10^5
    arr[i] < 10^5
    */
    ll arr[9] = {2,4,6,7,7,4,2,2,2};
    ll var1 = 0;
    fo(i,0,9){
        var1 = var1^arr[i];
    }
    cout<<"That integer is: "<<var1<<endl;

    return 0;
}