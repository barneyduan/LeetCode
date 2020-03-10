// practice make perfect :)
// Author: Duan Lian

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

struct SudoPoint {
  SudoPoint(int r, int c, char v)
    : r_(r),
      c_(c),
      v_(v) {}

  bool operator==(const SudoPoint &p) {
    return r_ == p.r_ || c_ == p.c_ ||
      (r_/3 == p.r_/3 && c_/3 == p.c_/3);
  }

  int r_;
  int c_;
  char v_;
};

struct SudoPointHash {
  size_t operator()(const SudoPoint &p) const {
    return std::hash<char>()(p.v_);
  }
};

class MySolution {
 public:
  // Write your code there...
  bool isValidSudoku(vector<vector<char>> &board) {
    unordered_map<char, list<SudoPoint>> map_;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        auto &v = board[i][j];
        if (v == '.') continue;
        else {
          SudoPoint p(i, j, v);
          auto it = map_.find(v);
          if (it == map_.end() ||
            find(it->second.begin(), it->second.end(), p) == it->second.end()) {
            map_[v].push_back(p);
          } else {
            return false;
          }
        }
      }
    }
    return true;
  }
};



