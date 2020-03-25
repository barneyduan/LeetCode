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
using PairItem = std::pair<int, int>;

struct CompaireOper {
  bool operator()(const PairItem &v1, const PairItem &v2) {
    return v1.second > v2.second;
  }
};

class MySolution {
 public:
  // Write your code there...
  vector<int> TopKFrequent(vector<int> &nums, int k) {
    std::unordered_map<int, int> map_;
    for (auto &i : nums) {
      map_[i]++;
    }

    std::priority_queue<std::pair<int, int>,
                        std::vector<pair<int, int>>, CompaireOper> min_heap_;

    for (auto i : map_) {
      min_heap_.push(i);
      if (min_heap_.size() > k) min_heap_.pop();
    }

    std::vector<int> res_;
    while (!min_heap_.empty()) {
      auto i = min_heap_.top();
      min_heap_.pop();
      res_.push_back(i.first);
    }

    std::reverse(res_.begin(), res_.end());
    return res_;
  }

};



