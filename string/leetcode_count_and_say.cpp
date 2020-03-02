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
  string countAndSay(int n) {
    string res = "1";
    if (n == 1) return res;
    string prev_str = "1";
    for (int i = 2; i < n; ++i) {
      res = "";
      int count = 1;
      int j = 1;
      for (j = 1; j < prev_str.size(); ++j) {
        if (prev_str[j] != prev_str[j-1]) {
          res += std::to_string(count) + prev_str[j-1];
          count = 1;
        } else {
          count++;
        }
      }
      res += std::to_string(count) + prev_str[j-1];
      prev_str = res;
    }
    return res;
  }
};



