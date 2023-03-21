#include <bits/stdc++.h>
using namespace std;
#define cin(a) int n; cin>>n; int a[n]; for(int i = 0; i < n; ++i) {cin>>a[i];}
#define cinv(v) int n; cin>>n; vector<int> v; for(int i=0; i<n; ++i){int xx; cin>>xx;}
#define lcou(v) {for(auto &x : v) cout<<x<<' '; cout<<"\n";}
// Kheiccha dp koron lagbo
#define ll long long int
int M = 1e9 + 7;



int main(){
    // Solution s;
    // int m, n;
    // vector<vector<int>> dp(n, vector<int> (m, 0));
    // vector<vector<bool>> vis(n, vector<bool> (m));
    // vector<int> dir = {0, 1, 0, -1, 0};
    // for (int i = 0; i < 4; i++)
    // {
    //     int dx = x + dir[i], dy = y + dir[i + 1];
    //     if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy] == '+'){
    //         q.push({dx, dy});
    //     }
    // }
    return 0;
}

struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {} ListNode(int x) : val(x), next(nullptr) {} ListNode(int x, ListNode *next) : val(x), next(next) {} };
struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode() : val(0), left(nullptr), right(nullptr) {} TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };