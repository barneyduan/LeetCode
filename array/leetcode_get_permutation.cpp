// practice make perfect :)
// Author: Duan Lian

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

class MySolution {
 public:
  // Write your code there...
  string get_permutation(int n, int k) {
    if (n == 1) return "1";
    vector<int> permutation(n, 0);
    for (int i = 0; i < n; i++) {
      permutation[i] = i+1;
    }
    stringstream res;
    k--; // k = 1 for first index 0 item
    for (int i = 0; i < n; i++) {
      int fac = fac_helper(n-i-1);
      int r = permutation_pop(permutation, k/fac, n-i);
      res << r;
      k %= fac;
    }
    return res.str();
  }

  int fac_helper(int n) {
    int res = 1;
    for (int i = 1; i < n; i++) {
      res *= (i+1);
    }
    return res;
  }

  int permutation_pop(vector<int> &permutation, int i, int size) {
    int res = permutation[i];
    for (; i < size-1; i++) {
      permutation[i] = permutation[i+1];
    }
    return res;
  }
};



