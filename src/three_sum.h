// Go for your dream, Barney

// Give an input array, get all possible 3 numbers
// whose sum equal 0
// question: https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1020/

#ifndef LEETCODE_THREE_SUM_H__
#define LEETCODE_THREE_SUM_H__

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {

  vector<vector<int> > result;
  // default compare function is <
  sort(nums.begin(), nums.end());
  // if min is already positive, we found nothing
  if (nums.size() < 3 || nums[0] > 0) {
    return result;
  }
  // fix the first number, if nums[i] == nums[i+1]
  // skip one
  for (size_t i = 0; i < nums.size() - 2; ++i) {
    if (i==0 || nums[i] != nums[i-1]) {
      int j = i + 1;
      int k = nums.size() - 1;
      int sum = 0 - nums[i];
      while (j < k) {
        if (nums[j] + nums[k] == sum) {
          vector<int> temp;
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
          result.push_back(temp);

          while (j < k && nums[j] == nums[j+1]) {
            j++;
          }
          while (j < k && nums[k] == nums[k-1]) {
            k--;
          }
          j++;
          k--;
        } else if (nums[j] + nums[k] > sum) {
          k--;
        } else {
          j++;
        }
      }


    }
  }

  return result;
}

#endif // THREE_SUM_H

