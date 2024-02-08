#include <bits/stdc++.h>
using namespace std;
#define ll long long
int M = 1e9 + 7;


// **** Maximum / Mininum / Summation ****
int maxIndex(vector<int> &nums){
    return max_element(begin(nums), end(nums)) - begin(nums);
}
int maxElement(vector<int> &nums){
    return *max_element(nums.begin(), nums.end());
}
int sumVector(vector<int> &nums){
    return accumulate(nums.begin(), nums.end(), 0);
}


// **** Binary to Decimal ****
int binToDec(string& s){
    int n = s.size(), cnt = 0, res = 0;
    while(n--){
        res += (s[n] == '1') * (1 << cnt);
        cnt++;
    }
    return res;
}


// **** Decimal to Binary ****
string decToBin(int n){
    string res;
    while(n){
        if(n & 1) res = '1' + res;
        else res = '0' + res;
        n /= 2;
    }
    return res;
}


// **** Prime or not - O(sqrt(N)) ****
bool isPrime(int n){
    if(n <= 1) return 0;
    int sq = sqrt(n);
    for (int i = 2; i <= sq; i++)
    {
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}


// **** No. of Divisors - O(sqrt(N)) ****
ll divCount(ll n){
    ll res = 0, sq = sqrt(n);
    for (int i = 1; i <= sq; i++)
    {
        if(n % i == 0){
            res += 2;
            if(n / i == i){
                res--;
            }
        }
    }
    return res;
}


// **** All Divisors - O(sqrt(N)) ****
vector<ll> divisors(ll n){
    vector<ll> res;
    int sq = sqrt(n);
    for (int i = 1; i <= sq; i++)
    {
        if(n % i == 0){
            res.push_back(i);
            if(n / i != i){
                res.push_back(n / i);
            }
        }
    }
    return res;
}


// **** pow(x, n) - O(log(N)) ****
ll exp(ll x, int n, ll m = M){
    ll res = 1;
    while(n){
        if(n & 1) {
            if(n > 0) {
                res = (res * x) % m;
            }
            else {
                res /= x;
            }
        }
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}


// **** logb(a) - O(log(N)) ****
ll logba(ll b, ll a) {
    ll res = 0;
    while(a > 1) {
        res++, a /= b;
    }
    if(pow(b, res) != a) res++;
    return res;
}


// **** Modulo operations ****
ll mod_add(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = M) {a = a % m; b = b % m; return (mod_mul(a, exp(b, m - 2, m), m) + m) % m;}


// **** Modulo Inverse ****
int inv(int i, int m = 1e9 + 7) {
    return i <= 1 ? i : m - (long long)(m / i) * inv(m % i) % m;
}


// **** Palindrome or not ****
bool isPal(string s, ll start, ll end){
    while(start <= end){
        if(s[start++] != s[end--]){
            return 0;
        }
    }
    return 1;
}


// **** Find factorial ****
ll fac(ll n, int m = M){
    ll res = 1;
    while(n){
        res = (res * n) % m;
        n--;
    }
    return res;
}


// **** nCr - O(r) ****
long nCr(int n, int r){
    if(r > n) {
        return nCr(r, n);
    }

    long res = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; i++)
    {
        res = res * (n - r + i) / i;
    }
    return res;
}


// **** Fibonacchi - O(N) ****
int fib(int n){
    if(n < 2) {
        return n;
    }
    int one = 0, two = 1;
    for(int i = 2; i <= n; i++){
        int temp = two;
        two += one;
        one = temp;
    }
    return two;
}


// **** Hash value ****
int hash(string s, int p = M){
    int res = 0, n = s.size();
    for (int i = 0; i < n; i++)
    {
        res = mod_add(res, mod_mul(s[n - 1 - i] - 'a' + 1, exp(26, i, p), p), p);
    }
    return res;
}


// **** LPS - O(N) ****
vector<int> lps(string& s) {
    int n = s.size(), i = 1, prevLPS = 0;
    vector<int> LPS(n, 0);
    while(i < n){
        if(s[i] == s[prevLPS]){
            LPS[i] = prevLPS + 1;
            prevLPS++, i++;
        }
        else if(prevLPS == 0){
            LPS[i] = 0, i++;
        }
        else{
            prevLPS = LPS[prevLPS - 1];
        }
    }
    return LPS;
}

// **** Sort by STL ****
static bool sortbysecasce(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}
static bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b){
    return a.second > b.second;
}
static bool sortbyvector(const vector<int> &a, const vector<int> &b){
    return a[1] < b[1];
}
// sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) -> bool{return a[1] < b[1];});


// **** Next permutation- O(N), O(N) ****
string nextPermutation(string s) {
    int i = s.size() - 1;
    while(i > 0 && s[i - 1] >= s[i]) {
        i--;
    }
    if(i == 0) {
        return "-1";
    }

    int j = s.size() - 1;
    while(j > 0 && s[j] <= s[i - 1]) {
        j--;
    }
    swap(s[j], s[i - 1]);
    reverse(s.begin() + i, s.end());
    return s;
}


// **** 2D prefix sum - O(N * M), O(N * M) ****
vector<vector<int>> prefixMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> pre(n, vector<int>(m));
    pre[0][0] = matrix[0][0];
    for (int i = 1; i < m; i++) {
        pre[0][i] = pre[0][i - 1] + matrix[0][i];
    }
    for (int i = 1; i < n; i++) {
        pre[i][0] = pre[i - 1][0] + matrix[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + matrix[i][j];
        }
    }
    return pre;
}

vector<vector<int>> suffixMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> suf(n, vector<int>(m));
    suf[n - 1][m - 1] = matrix[n - 1][m - 1];
    for (int i = m - 2; i >= 0; i--) {
        suf[n - 1][i] = suf[n - 1][i + 1] + matrix[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--) {
        suf[i][m - 1] = suf[i + 1][m - 1] + matrix[i][m - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            suf[i][j] = suf[i + 1][j] + suf[i][j + 1] - suf[i + 1][j + 1] + matrix[i][j];
        }
    }
    return suf;
}

int main() {
    long x = nCr(48, 24), y = nCr(24, 12);
    cout<<x<<endl;
}