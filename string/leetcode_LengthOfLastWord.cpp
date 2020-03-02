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
  int length_of_last_word(string s) {
    int res = 0;
    bool flag = false;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == ' ') {
        if (flag) break;
      } else {
        flag = true;
        res++;
      }
    }
    return res;
  }
};



