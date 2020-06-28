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
    int removeDuplicates(vector<int>& nums) {
      if (nums.empty()) return 0;
      int length = 0;
      int start = 0, s_c = 1;  // start_count
      int end = 0, e_c = 1;  // end_count
      for (int i = 0; i < nums.size(); i++) {
        if (i == nums.size()-1) {
          return nums.size();
        }
        if (s_c < 2) {
          if (nums[i+1] == nums[i]) {
            s_c++;
          }
        } else {  // s_c >= 2
          if (nums[i+1] == nums[i]) {
            start = i+1;
            break;
          } else {
            s_c = 1;
          }
        }
      }

      // if whole array is valid, then just return
      if (start == nums.size() - 1) return start;

      for (int j = start; j < nums.size(); j++) {
        if (j == nums.size()-1) {
          return start;
        }
        if (nums[j+1] != nums[j]) {
          end = j+1;
          break;
        }
      }

      if (end == nums.size() - 1) {
        swap(nums[end], nums[start++]);
        return start;
      }

      int i = 0;
      for (i = end; i < nums.size(); i++) {
        if (i == nums.size()-1) {
          if (e_c <= 2) {
            swap(nums[i], nums[start++]);
          }
          return start;
        }
        if (e_c < 2) {
          if (nums[i+1] == nums[i]) {
            e_c++;
          }
          swap(nums[i], nums[start++]);
        } else if (e_c == 2) {
          if (nums[i+1] != nums[i]) {
            e_c = 1;
          } else {
            e_c++;
          }
          swap(nums[i], nums[start++]);
        } else {
          if (nums[i+1] != nums[i]) {
            e_c = 1;
          }
        }
      }
      return start;
    }
};



