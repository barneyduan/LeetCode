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
  vector<int> spiral_order(vector<vector<int>> &matrix) {
    if (matrix.empty()) return vector<int>();
    vector<vector<int>> rot = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ang = 0;
    vector<int> res;
    int i = 0, j = 0;
    int left = 0, right = matrix.size(), up = 0, down = matrix[0].size();
    while (true) {
      do {
        res.push_back(matrix[i][j]);
        i += rot[ang][0];
        j += rot[ang][1];
      } while (is_valid(i, j, left, right, up, down));
      // revert one step
      i -= rot[ang][0];
      j -= rot[ang][1];
      // make rotation
      ang = (ang == 3) ? 0 : ang+1;
      // make next step
      i += rot[ang][0];
      j += rot[ang][1];
      if (!is_valid(i, j, left, right, up, down)) {
        break;
      }
      update_bound(rot[ang], left, right, up, down);
    }
    return res;
  }

  bool is_valid(int i, int j, int left, int right, int up, int down) {
    return i>=left && i<right && j>=up &&j<down;
  }

  void update_bound(vector<int> &rot, int &left, int &right,
                    int &up, int &down) {
    left += rot[0] > 0 ? rot[0] : 0;
    right += rot[0] < 0 ? rot[0] : 0;
    up += rot[1] > 0 ? rot[1] : 0;
    down += rot[1] < 0 ? rot[1] : 0;
  }
};

int main() {
  MySolution solution;
  vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
  vector<int> k = solution.spiral_order(m);
  for (auto i: k) {
    cout << i;
  }
  cout << endl;
}



