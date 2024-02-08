#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec vector<ll>
#define fo(i,n) for(int i = 0; i < n; i++)
#define rfo(i,n) for(int i = n - 1; i >= 0; i--)

int main(){
    // **** Faster way ****
    
    // ordered map

    map<int, string> m;
    m[2] = "abc";
    m[9] = "lwb";
    m[5] = "shc";
    m[10] = "ucj";
    m[1] = "klc";
    m[4] = "oac";
    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }    



    // unordered map

    unordered_map<int, string> m1;
    m1[2] = "abc";
    m1[9] = "lwb";
    m1[5] = "shc";
    m1[10] = "ucj";
    m1[1] = "klc";
    m1[4] = "oac";
    for(auto &pr : m1){
        cout<<pr.first<<" "<<pr.second<<endl;
    }


    return 0;
}