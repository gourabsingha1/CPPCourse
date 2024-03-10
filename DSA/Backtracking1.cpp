#include <bits/stdc++.h>
using namespace std;
#define cin(a) int n; cin>>n; int a[n]; fo(i,0,n){cin>>a[i];}
#define cinv(v) int n; cin>>n; vector<int> v; for(int i=0; i<n; ++i){int xx; cin>>xx; v.push_back(xx);}


// **** Get stairs path **** https://www.youtube.com/watch?v=hMJAlbJIS7E&list=PL-Jc9J83PIiFxaBahjslhBD1LiJAV7nKs&index=29
vector<string> getStairsPath(int n){
    if(n == 0){
        return {""};
    }
    else if(n < 0){
        return {};
    }

    vector<string> paths1 = getStairsPath(n - 1);
    vector<string> paths2 = getStairsPath(n - 2);
    vector<string> paths3 = getStairsPath(n - 3);
    vector<string> resPaths;
    for(auto& path : paths1){
        resPaths.push_back('1' + path);
    }
    for(auto& path : paths2){
        resPaths.push_back('2' + path);
    }
    for(auto& path : paths3){
        resPaths.push_back('3' + path);
    }
    return resPaths;
}


// **** Sums of all subsets ****
class SubsetSums{
public:
    void helper(int currInd, vector<int> &arr, int sum, vector<int> &res){
        if(currInd == arr.size()){
            res.push_back(sum);
            return;
        }
        helper(currInd + 1, arr, sum, res);
        helper(currInd + 1, arr, sum + arr[currInd], res);
    }
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> res;
        helper(0, arr, 0, res);
        return res;
    }
};


// **** Subsets ****
class Subsets{
public:
    void helper(int currInd, vector<int>& nums, vector<int> v, vector<vector<int>> &res){
        int n = nums.size();
        if(currInd == n){
            res.push_back(v);
            return;
        }
        v.push_back(nums[currInd]);
        helper(currInd + 1, nums, v, res);
        v.pop_back();
        helper(currInd + 1, nums, v, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0, nums, {}, res);
        return res;
    }
};


// **** Subsets II ****
class SubsetsII{
public:
    void helper(int currInd, vector<int>& nums, vector<int> v, vector<vector<int>> &res){
        int n = nums.size();
        res.push_back(v);
        for (int i = currInd; i < n; i++)
        {
            if(i != currInd && nums[i-1] == nums[i]) continue;
            v.push_back(nums[i]);
            helper(i + 1, nums, v, res);
            v.pop_back();
        }
    }

    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        helper(0, nums, {}, res);
        return res;
    }
};


// **** Permutations ****
class Permutations{
public:
    void helper1(vector<int>& nums, unordered_map<int, int> &m, vector<int> v, vector<vector<int>> &res){
        int n = nums.size();
        if(v.size() == n){
            res.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if(m[i]) continue;
            v.push_back(nums[i]);
            m[i] = 1; // marking as picked
            helper1(nums, m, v, res);
            v.pop_back();
            m[i] = 0; // marking as not picked
        }
    }
    void helper2(int currInd, vector<int>& nums, vector<vector<int>> &res){
        int n = nums.size();
        if(currInd == n){
            res.push_back(nums);
            return;
        }
        for (int i = currInd; i < n; i++)
        {
            swap(nums[i], nums[currInd]);
            helper2(currInd + 1, nums, res);
            swap(nums[i], nums[currInd]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> m;
        helper1(nums, m, {}, res);
        return res;
        // helper2(0, nums, res);
        // return res;
    }
};


// **** N Queens - O(N!), O(N * M) ****
class NQueens{
public:
    // go from top to bottom placing queens if position is valid

    bool isValid(int i, int j, int n, vector<string>& board) {
        // upper left
        int r = i, c = j;
        while(r >= 0 && c >= 0) {
            if(board[r--][c--] == 'Q') {
                return 0;
            }
        }
        // up
        r = i, c = j;
        while(r >= 0) {
            if(board[r--][c] == 'Q') {
                return 0;
            }
        }
        // upper right
        r = i, c = j;
        while(r >= 0 && c < n) {
            if(board[r--][c++] == 'Q') {
                return 0;
            }
        }
        return 1;
    }
    
    void helper(int i, int n, vector<string>& board, vector<vector<string>>& res) {
        if(i == n) {
            res.push_back(board);
            return;
        }
        
        for (int j = 0; j < n; j++)
        {
            if(isValid(i, j, n, board)) {
                board[i][j] = 'Q';
                helper(i + 1, n, board, res);
                board[i][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        helper(0, n, board, res);
        return res;
    }
};