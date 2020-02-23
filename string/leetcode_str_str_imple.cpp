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
  int strStr(string haystack, string needle) {
    if (needle.empty()) {
      return 0;
    }
    int m = haystack.size();
    int n = needle.size();
    int j = 0;
    for (int i = 0; i < m - n + 1; ++i) {
      for (j = 0; j < n; j++) {
        if (haystack[i + j] != needle[j]) {
          break;
        }
      }
      if (j == n) {
        return i;
      }
    }
    return -1;
  }

};



