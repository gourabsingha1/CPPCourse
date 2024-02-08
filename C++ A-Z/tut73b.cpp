#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec vector<ll>
#define fo(i,n) for(int i = 0; i < n; i++)
#define rfo(i,n) for(int i = n - 1; i >= 0; i--)

/* Q1. Given N strings, print unique strings in lexographical order with their frequency
N <= 10^5
|S| <= 100
*/

/* Q2. Given N strings and Q queries. In each query you are given a string. Print frequency of that string.
N <= 10^6
|S| <= 100
Q <= 10^6
*/ 

int main(){

// Q1-->
    map<string, int> m;
    int n;
    cin>>n;
    fo(i,n){
        string s;
        cin>>s;
        m[s] = m[s] + 1; // counting unique strings. intially m[s] = 0
    }
    for(auto pr : m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }

// // Q2-->
//     unordered_map<string, int>m;
//     int n;
//     cin>>n;
//     fo(i,n){
//         string s;
//         cin>>s;
//         m[s]++;
//     }
//     int q;
//     cin>>q;
//     fo(i,q){
//         string s;
//         cin>>s;
//         cout<<m[s]<<endl;
//     }

    return 0;
}