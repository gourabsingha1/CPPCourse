#include <bits/stdc++.h>
using namespace std;
#define cin(a) int n; cin>>n; int a[n]; for(int i = 0; i < n; ++i) {cin>>a[i];}
#define cinv(v) int n; cin>>n; vector<int> v; for(int i=0; i<n; ++i){int xx; cin>>xx; v.push_back(xx);}
#define lcou(v) {for(auto &x : v) cout<<x<<' '; cout<<"\n";}
#define ll long long

// **** bit manipulation ****

void printBinary(ll n){
    for (int i = 63; i >= 0; i--)
    {
        cout<<((n >> i) & 1);
    }
    cout<<endl;
}

// check odd
bool isOdd(ll num) {
    return num & 1;
}

// check power of 2
bool checkPowerOfTwo(ll num) {
    return num & (num - 1);
}

// check if ith bit is set bit
bool checkSetBit(ll num, int i) {
    return (num >> i) & 1;
}

// make the ith bit set bit
void setBit(ll num, int i) {
    num |= (1 << i);
}

// make the ith bit unset
void unsetBit(ll num, int i) {
    num &= (~(1 << i)); // ~ inverts the binary
}

// toggle the ith bit unset
void toggleBit(ll num, int i) {
    num ^= (1 << i);
}

// count set bits
ll countSetBits(ll num) {
    return __builtin_popcountll((1LL << num) - 1);
}

// divide by 2 (faster way)
ll divideByTwo(ll num) {
    return num >> 1;
}

// multiply by 2 (faster way)
ll multiplyByTwo(ll num) {
    return num << 1;
}

// difference bw uppercase and lowercase = 5th bit is set in lowercase
// uppercase to lowercase
char toLower(char ch) {
    return ch | (1 << 5);
}

// lowercase to uppercase
char toUpper(char ch) {
    return ch & (~(1 << 5));
}

// clear LSB (starting from the ith bit, clear LSB (unset bits))
ll clearLSB(ll num, ll i) {
    return num & ~((1 << (i + 1)) - 1);
}

// clear MSB (starting from the ith bit, clear MSB (unset bits))
ll clearMSB(ll num, ll i) {
    return num & ((1 << (i + 1)) - 1);
}


int main(){

    printBinary(43);
    printBinary(clearLSB(43, 2));
    printBinary(clearMSB(43, 2));

    return 0;
}