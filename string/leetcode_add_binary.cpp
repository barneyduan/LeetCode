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

class MySolution {
 public:
  // Write your code there...
  string add_binary(string a, string b) {
    int i = 1;
    int a_len = a.length();
    int b_len = b.length();
    int len = std::min<int>(a_len, b_len);
    int up = 0;
    string res = "";
    while (i <= len) {
      int v = up + (a[a_len-i] - '0') + (b[b_len-i] -'0');
      res += ((v%2) + '0');
      up = v/2;
      i++;
    }
    int a_len_2 = a_len - len;
    if (a_len_2 > 0) {
      for (int j = 1; j <= a_len_2; j++) {
        int v = up + (a[a_len_2-j] - '0');
        res += ((v%2) + '0');
        up = v/2;
      }
    }
    int b_len_2 = b_len - len;
    if (b_len_2 > 0) {
      for (int j = 1; j <= b_len_2; j++) {
        int v = up + (b[b_len_2-j] - '0');
        res += ((v%2) + '0');
        up = v/2;
      }
    }
    if (up == 1) {
      res += '1';
    }
    reverse(res.begin(), res.end());
    return res;
  }
};



