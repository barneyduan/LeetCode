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
  int searchInsert(vector<int> &nums, int target) {
    if (nums.empty()) {
      return 0;
    }
    auto size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] > target) {
        return i;
      } else if (nums[i] == target) {
        return i;
      }
    }
    return nums.size();
  }

  int searchInsert2(vector<int> &nums, int target) {
    if (nums.empty()) return 0;
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        return mid;
      }
    }
    return nums[left] >= target ? left : left + 1;
  }

};



