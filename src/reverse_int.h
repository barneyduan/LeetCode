// Go for your dream, Barney

// reverse the bit of a 32-bit integre
// question: https://leetcode-cn.com/problems/reverse-integer/

#ifndef LEETCODE_REVERSE_INT_H__
#define LEETCODE_REVERSE_INT_H__

#include <algorithm>
#include <climits>

using namespace std;

int reverse(int x) {

  int rev_x = 0;
  int rem = x / 10;
  int rev_rem = 0;
  while (rem != 0) {
    rev_rem = x % 10;
    // int overflow handle
    // to judge the m + n > INT_MAX, we can NOT use m + n > INT_MAX ?
    // because m+n might be overflowed, so we use m > INT_MAX - n
    // the same as m > INT_MAX/n for m*n ? INT_MAX
    if (INT_MAX / 10 < abs(rev_x) ||
        abs(rev_x * 10) > INT_MAX - abs(rev_rem)) {
      return 0;
    }
    rev_x = rev_x * 10 + rev_rem;
    x /= 10;
    rem = x / 10;
  }
  rev_rem = x % 10;
  if (INT_MAX / 10 < abs(rev_x) ||
      abs(rev_x * 10) > INT_MAX - abs(rev_rem)) {
    return 0;
  }
  rev_x = rev_x * 10 + rev_rem;
  return rev_x;
}

#endif // REVERSE_INT_H

