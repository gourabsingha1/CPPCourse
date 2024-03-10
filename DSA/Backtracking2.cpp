#include <bits/stdc++.h>
using namespace std;
#define cin(a) int n; cin>>n; int a[n]; fo(i,0,n){cin>>a[i];}
#define cinv(v) int n; cin>>n; vector<int> v; for(int i=0; i<n; ++i){int xx; cin>>xx; v.push_back(xx);}


// **** Sudoko - O(9^(N * M)), O(N * M) ****
class Sudoko {
public:
    bool isValid(int x, int y, char num, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            // row
            if(board[i][y] == num) {
                return 0;
            }
            // col
            if(board[x][i] == num) {
                return 0;
            }
        }
        // 3 x 3
        int x1 = x / 3 * 3, y1 = y / 3 * 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(board[x1 + i][y1 + j] == num) {
                    return 0;
                }
            }
        }
        return 1;
    }

    bool helper(vector<vector<char>>& board) {
        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                if(board[x][y] == '.') {
                    for (char num = '1'; num <= '9'; num++)
                    {
                        if(isValid(x, y, num, board)) {
                            board[x][y] = num;
                            if(helper(board)) {
                                return 1;
                            }
                        }
                    }
                    // you will reach here when you cannot fill up a cell
                    // set it to '.' for further operations
                    board[x][y] = '.';
                    return 0;
                }
            }
        }
        
        // you will reach here after filling up every cell
        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};

// 5 3 . 6 7 8 9 1 2
// 6 7 2 1 9 5 3 4 8
// . 9 8 3 4 2 5 6 7
// 8 5 9 7 6 1 4 2 3
// 4 2 6 8 5 3 7 . 1
// 7 1 3 9 . 4 8 5 6
// 9 6 . 5 3 7 2 8 4
// 2 8 7 4 1 9 6 3 5
// 3 4 5 2 8 6 1 7 9



// **** Rat In A Maze ****
class RanInAMaze{
public:
    vector<string> res;
    vector<int> dir = {1, 0, -1, 0, 1}; // down, left, up, right

    void helper(int x, int y, string cur, vector<vector<int>>& matrix, int n) {
        if(x == n - 1 && y == n - 1) {
            res.push_back(cur);
        }

        matrix[x][y] = 0;
        string s = "DLUR";
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < n && dy < n && matrix[dx][dy]){
                helper(dx, dy, cur + s[i], matrix, n);
            }
        }
        matrix[x][y] = 1;
    }

    vector<string> findPath(vector<vector<int>>& matrix, int n) {
        if(matrix[0][0] == 0) {
            return {};
        }
        
        helper(0, 0, "", matrix, n);
        return res;
    }
};