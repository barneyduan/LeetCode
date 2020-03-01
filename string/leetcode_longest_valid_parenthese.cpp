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
  int longestValidParenthese(string s) {
    if (s.empty()) return 0;
    stack<int> st;
    st.push(-1);
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        st.pop();
        // st.top() is the leftest valid '('
        if (st.empty()) {
          st.push(i);
        } else {
          res = max(res, i - st.top());
        }
      }
    }
    return res;
  }
};



