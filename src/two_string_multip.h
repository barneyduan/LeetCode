// Go for your dream, Barney

// calculate the result of two string multiply
// question: https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1015/


#ifndef LEETCODE_TWO_STRING_MULTIP_H__
#define LEETCODE_TWO_STRING_MULTIP_H__


#include <string>
#include <vector>
#include <math.h>

using namespace std;

string multiply(string num1, string num2) {

  if (!num1.compare("0") || !num2.compare("0")) {
    return "0";
  }
  int carry = 0;
  size_t size_1 = num1.size();
  size_t size_2 = num2.size();
  int multi_1 = 0;
  int multi_2 = 0;
  vector<int> result(size_1 + size_2, 0);
  string ans = "";

  for (size_t i = size_2; i != 0; i--) {
    multi_2 = num2[i-1] - '0';
    for (size_t j = size_1; j !=0; j--) {
      multi_1 = num1[j-1] - '0';
      result[size_1 + size_2 - i - j] += multi_1 * multi_2;
    }
  }

  for (size_t k = 0; k < result.size() - 1; ++k) {
    carry = result[k] / 10;
    result[k] %= 10;
    result[k + 1] += carry;
  }

  bool max_flag = false;
  for (size_t k = result.size(); k != 0; k--) {
    if (!max_flag && result[k-1] == 0) {
      continue;
    }
    max_flag = true;
    ans += result[k-1] + '0';
  }
  return ans;
}

#endif // TWO_STRING_MULTIP_H

