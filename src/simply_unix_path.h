// Go for your dream, Barney

// Given an input string, reverse the string word by word
// question: https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1011/

#ifndef LEETCODE_SIMPLY_UNIX_PATH_H__
#define LEETCODE_SIMPLY_UNIX_PATH_H__

#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path) {
  if (path.empty()) {
    return "";
  }

  vector<string> stack;
  size_t size = path.size();
  if (path[size - 1] != '/') {
    path += "/";
    size += 1;
  }
  string sub_str = "";
  for (size_t i = 1; i < size; ++i) {
  if (path[i] != '/') {
    sub_str += path[i];
    continue;
  } else {
    if (sub_str.compare("..") == 0) {
      if (!stack.empty()) {
        stack.pop_back();
      }
    } else if (sub_str.compare(".") != 0 && !sub_str.empty()) {
      stack.push_back(sub_str);
    }
    sub_str.clear();
  }
  }

  string result = "/";
  for (size_t k = 0; k < stack.size(); ++k) {
  if (k != 0) {
    result += "/";
  }
  result += stack[k];
  }
  return result;
}

#endif // SIMPLY_UNIX_PATH_H

