/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <ciso646>
using namespace std;

class Solution {
public:

    #define size_row 9
    #define size_col 9
    #define arr_size(arr) (sizeof(arr)/sizeof(*arr))

    bool dfs(vector<vector<char>>& board){
        int Y, X;
        for(int j =0; j < size_row; ++j){
            for(int i =0; i < size_row; ++i){
                if(board[j][i] == '.'){
                    Y = j;
                    X = i;
                    goto sss;
                }
            }
        }
        return true;
        sss:
        bool in_dom[10];
        fill_n(in_dom, arr_size(in_dom), true);
        for(int j = 0; j < size_row; ++j){
            if(board[j][X] != '.' and in_dom[board[j][X] - '0']){
                in_dom[board[j][X] - '0'] = false;
            }
        }
        for(int i = 0; i < size_col; ++i){
            if(board[Y][i] != '.' and in_dom[board[Y][i] - '0']){
                in_dom[board[Y][i] - '0'] = false;
            }
        }
        for(int j =(Y-Y%3); j < (Y-Y%3)+3; ++j){
            for(int i =(X-X%3); i < (X-X%3)+3; ++i){
                if(board[j][i] != '.' and in_dom[board[j][i] - '0']){
                    in_dom[board[j][i] - '0'] = false;
                }
            }
        }
        int state = 0;
        do{
            int NUM;
            int count = -1;
            for(int n=1; n <= 9; ++n){
                if(in_dom[n] and ++count == state){
                    NUM = n;
                    break;
                }
            }
            if(count != state){
                board[Y][X] = '.';
                return false;
            }
            board[Y][X] = NUM + '0';
            state++;
        }while(!dfs(board));
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};
// @lc code=end

