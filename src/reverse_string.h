// Go for your dream, Barney

// Given an input string, reverse the string word by word
// question: https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1011/

#ifndef LEETCODE_REVERSE_STRING_H__
#define LEETCODE_REVERSE_STRING_H__

#include <string>
#include <vector>

using namespace std;

void reverseWords(string &s) {

  vector<string> stack;
  bool find_first = false;
  size_t start = 0;
  size_t size = s.size();
  for (size_t i = 0; i < size; ++i) {
    if (!find_first && s[i] != ' ') {
      find_first = true;
      start = i;
    }
    if (find_first) {
      // find no-null char
      if (s[i] == ' ') {
        // if end with a sub string
        find_first = false;
      } else if (i == size - 1) {
        // or if we hit the end string
        find_first = false;
        // correct the i
        i += 1;
      }
      if (!find_first) {
        // we hit the end, or we do NOTHING
        stack.push_back(s.substr(start, i - start));
      }
    }
  }

  s.clear();
  for (vector<string>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it) {
    s += *it;
    if (it != stack.rend() - 1) {
      s += " ";
    }

  }

}

#endif // REVERSE_STRING_H
