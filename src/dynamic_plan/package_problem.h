// Fight for your dream, Barney

#ifndef LEETCODE_PACKAGE_PROBLEM_H__
#define LEETCODE_PACKAGE_PROBLEM_H__

#include <vector>
#include <math.h>

using namespace std;

// Package problem:
// f[i][v] = max{f[i-1][v], f[i-1][v-c[i]] + m[i]}


void package_problem(vector<vector<int> > &goods, int max_p) {

  vector<int> sub_f(max_p+1, 0);
  vector<vector<int> >f(goods.size(), sub_f);
  for (int v = goods[0][0]; v <= max_p; ++v) {
    f[0][v] = goods[0][1];
  }
  for (int i = 1; i < (int)goods.size(); ++i) {
    for (int v = max_p; v >= 0; --v) {
      if (v >= goods[i][0]) {
        f[i][v] = max(f[i-1][v], f[i-1][v-goods[i][0]] + goods[i][1]);
      } else {
        f[i][v] = f[i-1][v];
      }
    }
  }
  return;
}

void package_problem_single_array(vector<vector<int> > &goods, int max_p) {

  vector<int> f(max_p+1, 0);
  for (int i = 0; i < (int)goods.size(); ++i) {
    for (int v = max_p; v >= goods[i][0]; --v) {
      f[v] = max(f[v], f[v-goods[i][0]] + goods[i][1]);
    }
  }
  return;
}


void packageTestMain() {
  vector<vector<int> > goods;
  goods.push_back({5, 12});
  goods.push_back({4, 3});
  goods.push_back({7, 10});
  goods.push_back({2, 3});
  goods.push_back({6, 6});
  package_problem_single_array(goods, 15);
}

#endif // PACKAGE_PROBLEM_H

