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
  void set_zeros(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    bool row_flag = false;
    bool col_flag = false;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (matrix[i][j] == 0) {
          // set matrix[0][col] negative
          if (j == 0) {
            col_flag = true;
          }
          matrix[0][j] = 0;

          // set matrix[i][0] negative
          if (i == 0) {
            row_flag = true;
          }
          matrix[i][0] = 0;
        }
      }
    }
    // flush all negative row and col
    for (int i = col - 1; i >= 1; i--) {
      if (matrix[0][i] == 0) {
        for (int j = 0; j < row; j++) {
          matrix[j][i] = 0;
        }
      }
    }
    for (int i = row - 1; i >= 1; i--) {
      if (matrix[i][0] == 0) {
        for (int j = 0; j < col; j++) {
          matrix[i][j] = 0;
        }
      }
    }
    // handle matrix[0][0] situation
    if (matrix[0][0] == 0) {
      if (row_flag) {
        for (int i = 0; i < col; i++) {
          matrix[0][i] = 0;
        }
      }
      if (col_flag) {
        for (int i = 0; i < row; i++) {
          matrix[i][0] = 0;
        }
      }
    }
  }
};



