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
  bool exist(vector<vector<char>> &board, string word) {
    row_ = board.size();
    col_ = board[0].size();
    vector<vector<int>> help_vec(row_, vector<int>(col_, 0));
    for (int i = 0; i < row_; i++) {
      for (int j = 0; j < col_; j++) {
        if (helper_exist(board, help_vec, i, j, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }

  bool helper_exist(vector<vector<char>> &board, vector<vector<int>> &vec,
                    int i, int j, const string &word, int idx) {
    if (vec[i][j] == 1) return false;
    if (idx == word.size() - 1) return board[i][j] == word[idx];

    if (board[i][j] == word[idx]) {
      vec[i][j] = 1;
      for (auto &dir : direction) {
        i += dir[0];
        j += dir[1];
        if (safe_index(i, j) &&
            helper_exist(board, vec, i, j, word, idx+1)) {
              return true;
        }
        i -= dir[0];
        j -= dir[1];
      }
      vec[i][j] = 0;
    }
    return false;
  }

  inline bool safe_index(int i, int j) {
    if (i < 0 || i >= row_) {
      return false;
    }
    if (j < 0 || j >= col_) {
      return false;
    }
    return true;
  }

 private:
  vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int row_ = 0;
  int col_ = 0;
};



