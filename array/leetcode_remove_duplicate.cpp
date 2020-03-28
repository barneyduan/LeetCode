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
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) return 0;
    int j = 0;
    size_t size = nums.size();
    for (size_t i = 1; i < size; i++) {
      if (nums[i] != nums[j]) {
        nums[++j] = nums[i];
      }
    }
    return j+1;
  }
};



