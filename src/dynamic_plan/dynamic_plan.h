// Fight for your dream, Barney
// A code practice for dynamic planning algorithm

#ifndef LEET_CODE_DYNAMIC_PLAN_H__
#define LEET_CODE_DYNAMIC_PLAN_H__

#include <vector>
#include <math.h>

using namespace std;

// normal recurrence method
int max_cut_profit(const vector<int> &p, int n) {
  if (n == 0) {
    return 0;
  }
  int r = 0;
  for (int i = 1; i <=n; ++i) {
    r = max(r, p[i] + max_cut_profit(p, n-i));
  }
  return r;
}

// bak_up note method
int max_cut_profit_bak(const vector<int> &p, int n, vector<int> &r) {

  int q = 0;
  if (r[n] >=0) {
    return r[n];
  }
  if (n == 0) {
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    q = max(q, max_cut_profit_bak(p, n-i, r) + p[i]);
  }
  r[n] = q;
  return q;
}

int max_cut_profit_memo(const vector<int> &p, int n) {

  vector<int> r(p.size() + 1, -1);
  return max_cut_profit_bak(p, n, r);
}


int max_cut_profit_bottom_up(const vector<int> &p, int n) {

  if (n == 0) return 0;
  vector<int> r(p.size(), -1);
  r[0] = 0;
  for (int i = 1; i <=n; ++i) {
    int q = -1;
    for (int j = 1; j <= i; ++j) {
      q = max(q, r[i-j]+p[j]);
    }
    r[i] = q;
  }
  return r[n];
}

void dynamic_test_main() {

  vector<int> iron = {0, 1, 5, 8, 10, 17, 17, 20, 24, 30};
  int max_p = max_cut_profit_bottom_up(iron, 4);
  cout << "max profit:" << max_p <<endl;
}

#endif // DYNAMIC_PLAN_H

