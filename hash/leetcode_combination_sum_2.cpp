// practice make perfect :)
// Author: Duan Lian

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class MySolution {
 public:
  // Write your code there...
  struct VectorHash {
    size_t operator()(const vector<int> &vec) const {
      std::hash<int> hasher;
      size_t seed = 0;
      for (auto i : vec) {
        seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
      }
      return seed;
    }
  };

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    if (candidates.empty()) return vector<vector<int>>();
    unordered_set<vector<int>, VectorHash> res;
    vector<int> sub_res;
    sort(candidates.begin(), candidates.end());
    helper(candidates, 0, target, res, sub_res);
    vector<vector<int>> real_res;
    for (auto i : res) {
      real_res.push_back(i);
    }
    return real_res;
  }

  void helper(const vector<int> &candidates, int start, int target,
              unordered_set<vector<int>, VectorHash> &res, vector<int> &sub_res) {
    if (target == 0) {
      res.insert(sub_res);
      return;
    }

    if (target < 0) return;
    if (start == candidates.size()) return;
    if (candidates[start] > target) return;

    for (int i = start; i < candidates.size(); i++) {
      sub_res.push_back(candidates[i]);
      helper(candidates, i+1, target - candidates[i], res, sub_res);
      sub_res.pop_back();
    }
  }

};



