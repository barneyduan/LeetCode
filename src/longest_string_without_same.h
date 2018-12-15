// Go for your dream, Barney

// find the longest string without the same character
// question: https://leetcode-cn.com/explore/featured/card/bytedance/242/string/1012/

#ifndef LONGEST_STRING_WITHOUT_SAME_H__
#define LONGEST_STRING_WITHOUT_SAME_H__

#include <string>
#include <map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {

  if (s.empty()) {
    return 0;
  }

  size_t size = s.size();
  size_t max_v = 1;
  map<char, int> sub_str;
  for (int i = 0; i < size; ++i) {
    sub_str.insert(pair<char, int>(s[i], 1));
    for (int j = i + 1; j < size; ++j) {
      if (sub_str.find(s[j]) != sub_str.end()) {
        // means we hit the same
        max_v = max(max_v, sub_str.size());
        sub_str.clear();
        break;
      } else {
        sub_str.insert(pair<char, int>(s[j], 1));
        if (j == size - 1) {
          max_v = max(max_v, sub_str.size());
          sub_str.clear();
        }
      }
    }
  }

  max_v = max(max_v, sub_str.size());

  return max_v;

}

int lengthOfLongestSubstringImprove(string s) {

  size_t size = s.size();
  int ans = 0;
  map<char, int> sub_str;
  for (int i = 0, j = 0; j < size; ++j) {
    if (sub_str.find(s[j]) != sub_str.end()) {
      // means we hit the same
      i = max(i, sub_str.at(s[j]));
    }
    ans = max(ans, j - i + 1);
    sub_str[s[j]] = j + 1;
  }
  return ans;
}

#endif
