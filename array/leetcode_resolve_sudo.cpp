// practice make perfect :)
// Author: Duan Lian

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class MySolution {
 public:
  // Write your code there...
  void resolveSudo(vector<vector<char>> &board) {
    int row_size = board.size();
    int col_size = board[0].size();
    for (int i = 0; i < row_size; i++) {
      for (int j = 0; j < col_size; j++) {
        if (board[i][j] != '.') {
          int d = board[i][j] - '0';
          // init the sudo board
          place_number(board, i, j, d);
        }
      }
    }
    backsort(board, 0, 0);
  }

  void place_number(vector<vector<char>> &board, int row, int col, int value) {
    board[row][col] = value + '0';
    row_[row][value]++;
    col_[col][value]++;
    zone_[row/3*3 + col/3][value]++;
  }

  bool backsort(vector<vector<char>> &board, int row, int col) {
        if (board[row][col] != '.') {
      return place_next_number(board, row, col);
    }
    bool res = false;
    for (int i = 1; i <= 9; i++) {
      place_number(board, row, col, i);
      res = place_next_number(board, row, col);
      if (res) {
        return true;
      }
      cancel_place_number(board, row, col, i);
    }
    return res;
  }

  bool is_place_valid(vector<vector<char>> &board, int row, int col) {
    int val = board[row][col] - '0';
    return row_[row][val] <= 1 && col_[col][val] <= 1 &&
           zone_[row/3*3+col/3][val] <= 1;
  }

  bool place_next_number(vector<vector<char>> &board, int row, int col) {
    if (!is_place_valid(board, row, col)) {
      return false;
    }
    if (row == board.size() - 1 && col == board[0].size() - 1) {
      // already find the solution
      return true;
    }
    // NOTE(lianduan): col == size() - 1
    if (col == board[0].size() - 1) {
      col = 0;
      row = row + 1;
    } else {
      col += 1;
    }
    return backsort(board, row, col);
  }

  void cancel_place_number(vector<vector<char>> &board, int row, int col,
                           int value) {
    board[row][col] = '.';
    row_[row][value]--;
    col_[col][value]--;
    // row/3*3 + col/3 can define the 9 3*3 zone
    zone_[row/3*3+col/3][value]--;
  }

 private:
  // NOTE(lianduan): row_ need 10 size for 1-9 index
  int row_[9][10] = {0};
  int col_[9][10] = {0};
  int zone_[9][10] = {0};
};



