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
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> sub_res;
    combine_helper(res, sub_res, n, k , 1);
    return res;
  }

  void combine_helper(vector<vector<int>> &res, vector<int> &sub_res,
                      int n, int k, int i) {
    if (k == 0) {
      res.push_back(sub_res);
      return;
    }
    for (int j = i; j <= n; j++) {
      sub_res.push_back(j);
      combine_helper(res, sub_res, n, k-1, j+1);
      sub_res.pop_back();
    }
  }
};



