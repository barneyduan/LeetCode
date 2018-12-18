// Go for your dream, Barney

// find the longest string without the same character
// question: https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1014/

#ifndef LONGEST_COMMON_PREFIX_H
#define LONGEST_COMMON_PREFIX_H

#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

  if (strs.empty()) {
    return "";
  }

  string ans = "";
  int i = 1;
  char cha = '\0';
  if (strs.front().empty()) {
    return ans;
  }
  cha = strs.front()[0];
  while (cha != '\0') {
    for (vector<string>::iterator it = strs.begin() + 1; it != strs.end(); ++it) {
      if (it->size() < i) {
        return ans;
      }
      if (cha != (*it)[i-1]) {
        return ans;
      }
    }
    ans += cha;
    i++;
    if (strs.front().size() < i) {
      return ans;
    }
    cha = strs.front()[i-1];
  }
  return ans;
}

#endif // LONGEST_COMMON_PREFIX_H

