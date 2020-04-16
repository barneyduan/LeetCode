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

/**
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class MySolution {
 public:
  // Write your code there...
  vector<vector<int>> subset(vector<int> &nums) {
    vector<vector<int>> res;
    res.push_back(vector<int>());
    if (nums.empty()) {
      return res;
    }
    for (auto &i : nums) {
      res.push_back({i});
    }
    vector<int> sub_res;
    subset_helper(res, sub_res, nums, 2, 0);
    return res;
  }

  void subset_helper(vector<vector<int>> &res, vector<int> &sub_res,
                     const vector<int> &nums, int len, int start) {
    if (len > nums.size()) {
      return;
    }
    if (len == nums.size()) {
      res.push_back(nums);
      return;
    }
    int size = nums.size();
    for (int i = start; i < size; i++) {
      sub_res.push_back(nums[i]);
      backsort_helper(res, sub_res, nums, len-1, i+1, len);
      sub_res.pop_back();
    }
    subset_helper(res, sub_res, nums, len+1, start);
  }

  void backsort_helper(vector<vector<int>> &res, vector<int> &sub_res,
                       const vector<int> &nums, int len, int start, int size) {
    if (start == nums.size()) {
      if (sub_res.size() == size) {
        res.push_back(sub_res);
      }
      return;
    }
    if (len == 0) {
      if (sub_res.size() == size) {
        res.push_back(sub_res);
      }
      return;
    }

    for (int i = start; i < nums.size(); i++) {
      sub_res.push_back(nums[i]);
      backsort_helper(res, sub_res, nums, len-1, i+1, size);
      sub_res.pop_back();
    }
  }
};

class MySolution2 {
 public:
  // write your code there...
  vector<vector<int>> subset(vector<int> &nums) {
    vector<vector<int>> res;
    int length = nums.size();
    for (int i = 0; i < (1<<length); i++) {
      // it will have 2^n results
      vector<int> sub_res;
      for (int j = 0; j < length; j++) {
        if ((i>>j & 1) == 1) sub_res.push_back(nums[j]);
      }
      res.push_back(sub_res);
    }
    return res;
  }
};



