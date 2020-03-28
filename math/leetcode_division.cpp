// practice make perfect :)
// Author: Duan Lian

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class MySolution {
 public:
  // Write your code there...
  int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    if (divisor == 1) return dividend;
    if (divisor == -1) {
      if (dividend > INT_MIN) {
        return -dividend;
      } else {
        return INT_MAX;
      }
    }

    int sig = 1;
    if (dividend > 0) {
      sig = divisor > 0 ? 1 : -1;
    } else {
      sig = divisor > 0 ? -1 : 1;
    }

    long dividend_long = dividend;
    long divisor_long = divisor;
    int res = 0;
    div (abs(dividend_long), abs(divisor_long), res);
    return res * sig;
  }

  void div(long dividend, long divisor, int &res) {
    if (dividend < divisor) {
      // no extra div need to do
      return;
    }

    int sub_res = 1;
    long fac = divisor;
    // NOTE(lianduan): can't use fac+fac, will overflow
    while (dividend - fac >= fac) {
      sub_res += sub_res;
      fac += fac;
    }
    res += sub_res;
    div(dividend - fac, divisor, res);
  }
};



