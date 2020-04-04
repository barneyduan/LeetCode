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
  /***
   * [3, 4, -1, 1] => [3, 4, 1, 1] => [-3, -4, 1, -1]
   * ([4, 1, x, 3] exist... and we got x is 2)
   */
  int first_missing_positive(vector<int> &nums) {
    // if 1 not exist, direct return 1
    size_t size = nums.size();
    bool contain_1 = false;
    for (int i = 0; i < size; i++) {
      if (nums[i] == 1) {
        contain_1 = true;
      }
    }
    // if not exist 1, got it
    if (!contain_1) return 1;
    // if only 1 items, got it
    if (size == 1) return 2;
    // convert all invalid number into 1
    for (int i = 0; i < size; i++) {
      if (nums[i] <= 0 || nums[i] > size) {
        nums[i] = 1;
      }
    }
    // if i--->nums[i] > 0, replace with -i
    // then we can find first positive pos
    for (int i = 0; i < size; i++) {
      size_t real_pos = abs(nums[i]);
      real_pos = real_pos == size ? 0 : real_pos;
      if (nums[real_pos] > 0) {
        nums[real_pos] = -nums[real_pos];
      }
    }

    for (int i = 1; i < size; i++) {
      if (nums[i] > 0) {
        return i;
      }
    }
    return nums[0] > 0 ? size : size + 1;
  }
};



