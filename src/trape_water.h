// Fight for your dream, Barney

// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining

// question: https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1047/

#ifndef LEETCODE_TRAPE_WATER_H__
#define LEETCODE_TRAPE_WATER_H__

#include <vector>
#include <math.h>

using namespace std;

int trap(vector<int>& height) {

  if (height.empty()) {
    return 0;
  }

  int max_h = 0, max_i = 0;
  int result = 0;
  int n = height.size();

  for (int i = 0; i < n; ++i) {
    if (height[i] > max_h) {
      max_h = height[i];
      max_i = i;
    }
  }
  int local_max = 0;
  for (int i = 0; i < max_i; ++i) {
    local_max = max(local_max, height[i]);
    result += local_max - height[i];
  }
  local_max = 0;
  for (int i = n - 1; i > max_i; --i) {
    local_max = max(local_max, height[i]);
    result += local_max - height[i];
  }

  return result;
}

#endif // TRAPE_WATER_H

