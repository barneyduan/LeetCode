// Go for your dream, Barney

// Search some target in a rotation array
// the complexity is at most O(logN)
// question: https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1017/

#ifndef LEETCODE_SEARCH_TARGET_IN_ROTATION_ARRAY_H__
#define LEETCODE_SEARCH_TARGET_IN_ROTATION_ARRAY_H__

#include <vector>

//0 1 2 3 4 5 6 7

//4 5 6 7 0 1 2 3

using namespace std;

int __searchInRotationArray(vector<int>& nums, int left, int right, int target) {

  int middle = left + (right - left)/2;
  if (nums[middle] == target) {
    return middle;
  } else if (left == right) {
    return -1;
  }

  if (nums[middle] >= nums[left]) {
    // left part is ordered
    if (nums[middle] > target && nums[left] <= target) {
      return __searchInRotationArray(nums, left, middle-1, target);
    } else {
      return __searchInRotationArray(nums, middle+1, right, target);
    }
  } else {
    // right part is ordered
    if (nums[middle] < target && nums[right] >= target) {
      return __searchInRotationArray(nums, middle+1, right, target);
    } else {
      return __searchInRotationArray(nums, left, middle-1, target);
    }
  }
}

int searchInRotationArray(vector<int>& nums, int target) {

  if (nums.empty()) {
    return -1;
  }
  size_t size = nums.size();

  return __searchInRotationArray(nums, 0, size-1, target);

}

#endif // SEARCH_TARGET_IN_ROTATION_ARRAY_H

