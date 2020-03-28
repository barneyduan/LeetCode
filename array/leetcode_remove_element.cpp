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
  int removeElement(vector<int> &nums, int val) {
    if (nums.empty()) return 0;
    int j = 0;
    size_t size = nums.size();
    for (; j < size; j++) {
      if (nums[j] != val) {
        break;
      }
    }
    if (j == size) return 0;
    swap(nums[0], nums[j]);
    j = 0;
    for (size_t i = j+1; i < size; i++) {
      if (nums[i] != val) {
        nums[++j] = nums[i];
      }
    }
    return j+1;
  }

};



