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


// **** N Queens ****
class Sol5{
    public:
        bool isSafe(int row, int col, vector<string> &v){
            // left upper diagonal
            int duprow = row, dupcol = col;
            while(row>=0 && col>=0){
                if(v[row][col]=='Q'){
                    return false;
                }
                row--;
                col--;
            }
            //left row
            row = duprow, col = dupcol;
            while(col>=0){
                if(v[row][col]=='Q'){
                    return false;
                }
                col--;
            }
            // left lower diagonal
            row = duprow, col = dupcol;
            while(row<v.size() && col>=0){
                if(v[row][col]=='Q'){
                    return false;
                }
                row++;
                col--;
            }
            return true;
        }
        vector<vector<string>> NQueens(int col, vector<string> &v, vector<vector<string>> &s){
            if(col==v.size()){
                s.push_back(v);
                return s;
            }
            for (int row = 0; row < v.size(); row++)
            {
                if(isSafe(row,col,v)){
                    v[row][col] = 'Q';
                    NQueens(col+1,v,s);
                    v[row][col] = '.';
                }
            }
            return s;
        }
    // int n; cin>>n;
    // vector<string> v;
    // vector<vector<string>> s;
    // fo(i,0,n){
    //     string st(n,'.');
    //     v.push_back(st)
    // }
    // Sol5 s5;
    // for(auto &y : s5.NQueens(0,v,s)){
    //     for(auto &y : x){
    //         cou(y)
    //     }nl
    // }

    public:
        /* lower diagonal = row+col, upper diagonal = n-1+col-row, left row = row. Mark them visited */
        vector<vector<string>> NQueens2(int col, vector<string> &v, vector<int> &lowD, vector<int> &upD, vector<int> &lRow, vector<vector<string>> &s){
            if(col==v.size()){
                s.push_back(v);
                return s;
            }
            for (int row = 0; row < v.size(); row++)
            {
                if(lowD[row+col]==0 && upD[v.size()-1+col-row]==0 && lRow[row]==0){
                    v[row][col] = 'Q';
                    lowD[row+col] = 1;
                    upD[v.size()-1+col-row] = 1;
                    lRow[row] = 1;
                    NQueens2(col+1, v, lowD, upD, lRow, s);
                    v[row][col] = '.';
                    lowD[row+col] = 0;
                    upD[v.size()-1+col-row] = 0;
                    lRow[row] = 0;
                }
            }
            return s;
        }
    // int n; cin>>n;
    // vector<string> v;
    // vector<int> lowD(2*n-1,0), upD(2*n-1,0), lRow(n,0);
    // vector<vector<string>> s;
    // fo(i,0,n){
    //     string st(n,'.');
    //     v.push_back(st)
    // }
    // Sol5 s5;
    // for(auto &y : s5.NQueens2(0, v, lowD, upD, lRow, s)){
    //     for(auto &y : x){
    //         cou(y)
    //     }nl
    // }
};


int main(){


    return 0;
}