// Copyright (c) 2020 Agora io. Inc
//

namespace agora {

}  // namespace agora
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

class Ugly {
 public:
  Ugly() {
    vec = {0, 1};
    int i2 = 1, i3 = 1, i5 = 1;
    for (int i = 0; i < 1690; i++) {
      int n2 = 2 * vec[i2];
      int n3 = 3 * vec[i3];
      int n5 = 5 * vec[i5];
      int ugly = std::min<int>(n2, n3);
      ugly = std::min<int>(ugly, n5);
      vec.push_back(ugly);
      if (ugly == n2) ++i2;
      if (ugly == n3) ++i3;
      if (ugly == n5) ++i5;
    }
  }

 public:
  std::vector<int> vec;
};

class MySolution {
 public:
  // Write your code there...
  int nth_ugly_number(int n) {
    static Ugly h;
    return h.vec[n];
  }
};

class Ugly2 {
 public:
  Ugly2() {
    vec = {0,};
    min_h.push(1);
    for (int i = 0; i < 1690; i++) {
      long n = min_h.top();
      vec.push_back(n);
      min_h.pop();
      long n2 = 2 * n;
      long n3 = 3 * n;
      long n5 = 5 * n;
      if (hash.find(n2) == hash.end()) {
        min_h.push(n2);
        hash[n2] = 1;
      }
      if (hash.find(n3) == hash.end()) {
         min_h.push(n3);
         hash[n3] = 1;
      }
      if (hash.find(n5) == hash.end()) {
        min_h.push(n5);
        hash[n5] = 1;
      }
    }
  }

 public:
  std::vector<int> vec;
  std::priority_queue<long, std::vector<long>, std::greater<long>> min_h;
  std::unordered_map<long, int> hash;
};


