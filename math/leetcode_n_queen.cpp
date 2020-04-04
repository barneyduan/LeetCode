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
  vector<int> row;
  vector<int> col;
  vector<int> diag;
  vector<int> anti_diag;
  vector<vector<string>> solve_n_queen(int n) {
    // init the board
    vector<vector<string>> res;
    vector<string> sub_res(n, std::string(n, '.'));
    row.resize(n, 0);
    col.resize(n, 0);
    diag.resize(2*n, 0);
    anti_diag.resize(3*n, 0);

    backsort_helper(res, sub_res, 0, 0, n, -1);
    return res;
  }

  void backsort_helper(vector<vector<string>> &res, vector<string> &sub_res,
                       int r, int c, int n, int last_r) {
    for (int i = r; i < n; i++) {
      for (int j = c; j < n; j++) {
        // we might skip a whole row, thus we need last_r to skip this fault
        bool suc = place_queen(sub_res, i, j, n);
        if (suc) {
          if ((i-last_r) < 2) {
            last_r = i;
            place_next_queen(res, sub_res, i, j, n, last_r);
          }
          pop_queen(sub_res, i, j, n);
          // need to revert last_r
          last_r--;
        }
      }
    }
  }

  bool place_queen(vector<string> &sub_res, int r, int c, int n) {
    if (row[r] || col[c] || diag[r+c] || anti_diag[r-c+n]) {
      return false;
    }
    sub_res[r][c] = 'Q';
    row[r]++;
    col[c]++;
    diag[r+c]++;
    anti_diag[r-c+n]++;
    return true;
  }

  void pop_queen(vector<string> &sub_res, int r, int c, int n) {
    sub_res[r][c] = '.';
    row[r]--;
    col[c]--;
    diag[r+c]--;
    anti_diag[r-c+n]--;
  }

  void place_next_queen(vector<vector<string>> &res, vector<string> &sub_res,
                        int r, int c, int n, int last_r) {
    if (r == n-1) {
      res.push_back(sub_res);
      return;
    }
    backsort_helper(res, sub_res, r+1, 0, n, last_r);
  }
};

int main() {
  MySolution solution;
  vector<vector<string>> k = solution.solve_n_queen(4);
  for (auto i : k) {
    for (auto str : i) {
      cout << str << endl;
    }
    cout << "-------" << endl;
  }
}



