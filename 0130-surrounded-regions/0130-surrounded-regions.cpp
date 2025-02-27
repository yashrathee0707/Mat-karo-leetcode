#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, 
        vector<vector<char>> &mat, int delrow[], int delcol[]) {
            vis[row][col] = 1; 
            int n = mat.size();
            int m = mat[0].size();
            
            // check for top, right, bottom, left 
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 
                // check for valid coordinates and unvisited 'O's
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                    dfs(nrow, ncol, vis, mat, delrow, delcol); 
                }
            }
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delrow[] = {-1, 0, 1, 0}; // Directions: UP, RIGHT, DOWN, LEFT
        int delcol[] = {0, 1, 0, -1};

        // Traverse first and last row
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, delrow, delcol);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1, j, vis, board, delrow, delcol);
            }
        }

        // Traverse first and last column
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, delrow, delcol);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, vis, board, delrow, delcol);
            }
        }

        // Replace unvisited 'O' with 'X'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';  // Fix assignment operator
                }
            }
        }
    }
};
