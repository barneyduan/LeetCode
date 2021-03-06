// fight for your dream, Barney

// find the max profit for a given stock
// dynamic plan problem
// question:

#ifndef LEETCODE_MAX_STOCK_PROFIT_H__
#define LEETCODE_MAX_STOCK_PROFIT_H__

#include <vector>
#include <math.h>

using namespace std;

int maxProfit(vector<int>& prices) {

  if (prices.empty()) return 0;
  int minv = prices[0];
  int maxv = 0;
  for (int i = 1; i < prices.size(); ++i) {
    maxv = max(maxv, prices[i] - min);

    minv = min(minv, prices[i]);
  }

  return maxv;
}


void dynamicPlanTestMain() {

}

#endif
