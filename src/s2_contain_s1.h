// Go for your dream, Barney

// a function to detect if the s2 contain s1
// question: https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1016/

#ifndef LEETCODE_S2_CONTAIN_S1_H__
#define LEETCODE_S2_CONTAIN_S1_H__

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/// 1. create all possible string for s1
/// full permutation: is each number swap with its later number
/// full non-repeat permutation: when i and j to swap, j cant appear at
/// [i, j) for once...
/// full assembly:
///
/// 2. check if exist in s2
///
///

void swapString(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

bool isSwapable(string s1, int start, int end) {

  for (; start < end; ++start) {
    if (s1[end] == s1[start]) {
      return false;
    }
  }
  return true;
}

void createAllRange(string s1, int start, vector<string> &ans) {
  if (start == s1.size() - 1) {
    ans.push_back(s1);
    cout << s1 << endl;
  }

  for (int i = start; i < s1.size(); ++i) {

    swapString(&s1[start], &s1[i]);
    createAllRange(s1, start+1, ans);
    swapString(&s1[start], &s1[i]);

  }
}

void createAllRangeWithoutRepeat(string s1, int start, vector<string> &ans) {
  if (start == s1.size() - 1) {
    ans.push_back(s1);
    cout << s1 << endl;
  }

  for (int i = start; i < s1.size(); ++i) {
    if (isSwapable(s1, start, i)) {
      swapString(&s1[start], &s1[i]);
      createAllRangeWithoutRepeat(s1, start+1, ans);
      swapString(&s1[start], &s1[i]);
    }
  }
}

void createPermutation(string s1, vector<string> &ans) {
  ans.clear();
  if (s1.empty()) {
    return;
  }

  //createAllRange(s1, 0, ans);
  createAllRangeWithoutRepeat(s1, 0, ans);
}

bool checkInclusion(string s1, string s2) {

  if (s1.empty() || s2.empty()) {
    return false;
  }
}

#endif // S2_CONTAIN_S1_H
