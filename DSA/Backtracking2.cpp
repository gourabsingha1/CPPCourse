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
#define vass(v,s) v.assign(s.begin(),s.end());
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
#define cy(x) {if(x) cou("YES") else cou("NO")}
#define siz(v) v.size()
ll M = 1e9+7;


// **** Sudoko ****
class Sol1{
    public:
        bool isValid(ll row, ll col, char c, vvc &v){
            fo(i,0,9){
                // finding c in column
                if(v[i][col]==c){
                    return false;
                }
                // finding c in row
                if(v[row][i]==c){
                    return false;
                }
                // finding c in submatrix
                if(v[3*(row/3) + i/3][3*(col/3) + i%3]==c){
                    return false;
                }
            }
            return true;
        }
        bool Sudoko(vvc &v){
            fo(i,0,v.size()){
                fo(j,0,v[i].size()){
                    if(v[i][j]=='.'){
                        for(char c='1'; c<='9';c++){
                            if(isValid(i,j,c,v)){
                                v[i][j] = c;
                                if(Sudoko(v)==true){ // recursion
                                    return true; // returning new organised sudoko
                                }
                                else{
                                    v[i][j] = '.';
                                }
                            }
                        }
                    }
                }
            }
            return true;
        }
};
    // vvc v;
    // fo(i,0,9){
    //     vc w;
    //     fo(j,0,9){
    //         char c; cin>>c;
    //         w.pb(c)
    //     }
    //     v.pb(w)
    // }nl
    // Sol1 s1;
    // s1.Sudoko(v);
    // afo(v){
    //     lcou(x)
    // }

// 5 3 . 6 7 8 9 1 2
// 6 7 2 1 9 5 3 4 8
// . 9 8 3 4 2 5 6 7
// 8 5 9 7 6 1 4 2 3
// 4 2 6 8 5 3 7 . 1
// 7 1 3 9 . 4 8 5 6
// 9 6 . 5 3 7 2 8 4
// 2 8 7 4 1 9 6 3 5
// 3 4 5 2 8 6 1 7 9



// **** Rat In A Maze lexographical (D>L>R>U) ****
class Sol3{
    public:
        vvs ratMaze(vs &a){
            ll n = siz(a);
            vs v;
            vvs s;
            vvl vv(n, vl(n, 0)); // marking NxN matrix not visited
            
            if(a[0][0]=='1'){
                RM(0, 0, v, vv, s, a);
            }
            return s;
        }

        void RM(ll i, ll j, vs &v, vvl &vv, vvs &s, vs &a){
            if(i==siz(a)-1 && j==siz(a)-1){
                s.pb(v)
                return;
            }

            // down
            if(i+1<siz(a) && a[i+1][j]=='1' && vv[i+1][j]==0){
                vv[i+1][j] = 1;
                v.pb("D")
                RM(i+1, j, v, vv, s, a);
                v.pop_back();
                vv[i+1][j] = 0;
            }
            // left
            if(j-1>=0 && a[i][j-1]=='1' && vv[i][j-1]==0){
            vv[i][j-1] = 1;
            v.pb("L")
            RM(i, j-1, v, vv, s, a);
            v.pop_back();
            vv[i][j-1] = 0;
            }
            // right
            if(j+1<siz(a) && a[i][j+1]=='1' && vv[i][j+1]==0){
                vv[i][j+1] = 1;
                v.pb("R")
                RM(i, j+1, v, vv, s, a);
                v.pop_back();
                vv[i][j+1] = 0;

            }
            // up
            if(i-1>=0 && a[i-1][j]=='1' && vv[i-1][j]==0){
                vv[i-1][j] = 1;
                v.pb("U")
                RM(i-1, j, v, vv, s, a);
                v.pop_back();
                vv[i-1][j] = 0;
            }
            return;
        }


        vvc ratMaze2(vs &a){
            ll n = siz(a);
            vc v;
            vvc s;
            vvl vv(n, vl(n, 0));
                    // D   L  R   U <-- Direction
                    // 0   1  2   3 <-- Index
            ll di[] = {+1, 0, 0, -1}; // to reduce if statements
            ll dj[] = {0, -1, +1, 0};

            if(a[0][0]=='1'){
                RM2(0, 0, v, vv, di, dj, s, a);
            }
            return s;
        }

        void RM2(ll i, ll j, vc &v, vvl &vv, ll di[], ll dj[], vvc &s, vs &a){
            if(i==siz(a)-1 && j==siz(a)-1){
                s.pb(v)
                return;
            }
            string dir = "DLRU";
            fo(ind,0,4){
                ll nexti = i + di[ind];
                ll nextj = j + dj[ind];
                if(nexti>=0 && nexti<siz(a) && nextj>=0 && nextj<siz(a) && vv[nexti][nextj]==0 && a[nexti][nextj]=='1'){
                    vv[i][j] = 1;
                    v.pb(dir[ind])
                    RM2(nexti, nextj, v, vv, di, dj, s, a);
                    v.pop_back();
                    vv[i][j] = 0;
                }
            }
        }
};
    // ll n;
    // cin>>n;
    // vs v;
    // fo(i,0,n){
    //     string s;
    //     cin>>s;
    //     v.pb(s)
    // }
    // Sol3 s3;
    // afo(s3.ratMaze(v)){
    //     for(auto &y : x){
    //         cout<<y;
    //     }nl
    // }

    // Sol3 s3;
    // afo(s3.ratMaze2(v)){
    //     for(auto &y : x){
    //         cout<<y;
    //     }nl
    // }



// **** Find the K-th permutation ****
class Sol4{
    public:
        vl kthPer(ll n, ll k){
            k--; // 0 based index
            vl s;
            list<ll> ls;
            fo(i,0,n){
                ls.pb(i+1)
            }
            KP(0, s, ls, n, k);
            return s;
        }

        ll fac(ll n){
            ll ans = 1;
            while(n>0){
                ans = ans*n;
                n--;
            }
            return ans;
        }

        void KP(ll i, vl &s, list<ll> &ls, ll n, ll k){
            if(siz(s)==n){
                return;
            }
            ll d = fac(n - i - 1);
            auto it = ls.begin();
            fo(j,0,k/d){
                it++;
            }
            s.pb(*it)
            it = ls.erase(it);
            KP(i+1, s, ls, n, k%d);
        }
    // ll n,k;
    // cin>>n>>k;
    // Sol4 s4;
    // lcou(s4.kthPer(n,k))


        string kthPer2(ll n, ll k){
            ll fact = 1;
            vl v;
            fo(i,1,n){
                fact*=i;
                v.pb(i)
            }
            v.pb(n)
            string ans = "";
            k--;
            while(1){
                ans = ans + to_string(v[k/fact]);
                v.erase(v.begin() + k/fact);
                if(siz(v)==0){
                    break;
                }
                k = k%fact;
                fact = fact/siz(v);
            }
            return ans;
        }
};
    // ll n,k;
    // cin>>n>>k;
    // Sol4 s4;
    // cou(s4.kthPer2(n,k))


int main(){
    ll n,k;
    cin>>n>>k;
    Sol4 s4;
    cou(s4.kthPer2(n,k))

    
    return 0;
}