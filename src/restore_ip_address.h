// Go for your dream, Barney

// Give an input string, get all possible results ip address
// question: https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1044/

#ifndef LEETCODE_RESTORE_IP_ADDRESS_H__
#define LEETCODE_RESTORE_IP_ADDRESS_H__

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

bool isValid(string s) {
  int num;
  stringstream ss;
  ss << s;
  ss >> num;
  if (s.size() > 1) {
    return s[0] != '0' && num >= 0 && num < 256;
  }
  return num >= 0 && num < 256;
}

void DFS(string t, string s, vector<string> &r, int count) {
  if (count == 3) {
    if (isValid(s)) {
      r.push_back(t+s);
    }
    return;
  }

  for (int i = 1; i < 4 && i < s.size(); ++ i) {
    string sub = s.substr(0, i);
    if (isValid(sub)) {
      DFS(t+sub+'.', s.substr(i), r, count+1);
    }
  }
}

vector<string> restoreIpAddresses(string s) {

  vector<string> result;
  string t;
  DFS(t, s, result, 0);
  return result;

}

#endif // RESTORE_IP_ADDRESS_H

