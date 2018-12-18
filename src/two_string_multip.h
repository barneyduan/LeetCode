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

  int up_bit = 0;
  int down_bit = 0;
  int multi_1 = 0;
  int multi_2 = 0;
  int sub_res = 0;
  vector<int> result;

  for (int i = 0; i < num2.size(); ++i) {
    sub_res = 0;
    multi_2 = num2[i] - '0';
    for (int j = 0; j < num1.size(); ++j) {
      multi_1 = num1[j] - '0';
      down_bit = multi_1 * multi_2 % 10 + up_bit;
      up_bit = multi_1 * multi_2 / 10;
      sub_res += down_bit * pow(10, j);
    }
    sub_res += up_bit * pow(10, j);
    result.push_back(sub_res * pow(10, i));
  }
}

#endif // TWO_STRING_MULTIP_H

