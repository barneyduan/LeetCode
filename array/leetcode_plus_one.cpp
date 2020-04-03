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
  vector<int> plusOne(vector<int> &digits) {
    int plus = 1;
    vector<int> res;
    for (auto i = digits.rbegin(); i != digits.rend(); i++) {
      int r = *i + plus;
      if (r > 9) {
        r = 0;
        plus = 1;
      } else {
        plus = 0;
      }
      res.push_back(r);
    }
    if (plus != 0) res.push_back(plus);
    reverse(res.begin(), res.end());
    return res;
  }
};

class BestSolution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    for (auto i = digits.rbegin(); i != digits.rend(); i++) {
      (*i)++;
      (*i) %= 10;
      if (*i != 0) return digits;
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};



