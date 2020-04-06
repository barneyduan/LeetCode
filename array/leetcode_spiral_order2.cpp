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
  struct board_t {
    int left;
    int right;
    int up;
    int down;
  };
  vector<vector<int>> spiral_order_2(int n) {
    vector<vector<int>> rot = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> res(n, vector<int>(n, 0));
    int ang = 0;
    int i = 0, j = 0;
    int val = 1;
    board_t board;
    board.left = 0;
    board.right = n;
    board.up = 0;
    board.down = n;
    while (true) {
      do {
        res[i][j] = val;
        val++;
        i += rot[ang][0];
        j += rot[ang][1];
      } while (is_valid(i, j, board));
      // revert one step
      i -= rot[ang][0];
      j -= rot[ang][1];
      // make rotation
      ang = (ang == 3) ? 0 : ang+1;
      // make next step
      i += rot[ang][0];
      j += rot[ang][1];
      if (!is_valid(i, j, board)) {
        break;
      }
      update_bound(rot[ang], board);
    }
    return res;
  }

  bool is_valid(int i, int j, const board_t &board) {
    return i>=board.left && i<board.right && j>=board.up &&j<board.down;
  }

  void update_bound(vector<int> &rot, board_t &board) {
    board.left += rot[0] > 0 ? rot[0] : 0;
    board.right += rot[0] < 0 ? rot[0] : 0;
    board.up += rot[1] > 0 ? rot[1] : 0;
    board.down += rot[1] < 0 ? rot[1] : 0;
  }
};



