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
  void sort_colors(vector<int> &nums) {
    if (nums.empty()) return;
    int size = nums.size();
    int red = 0;
    int white = 0;
    int blue = size - 1;
    int i = 0;
    while (i <= blue) {
      if (nums[i] == 0) {
        // red
        swap(nums[white], nums[i]);
        white++;
        i++;
      } else if (nums[i] == 1) {
        // white
        i++;
      } else {
        // blue
        swap(nums[blue], nums[i]);
        blue--;
        // continue again i
      }
    }
  }
};



