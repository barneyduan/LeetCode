// Practice make perfect
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace leetcode {

class MySolution {
 public:
  vector<string> generateParenthesis(int n) {
    if (n == 0) {
      return vector<string>();
    }
    vector<string> res;
    helper("", n, n, res);
    return res;
  }

  void helper(const string &str, int left, int right, vector<string> &res) {
    if (left == 0) {
      if (right == 0) {
        res.push_back(str);
        return;
      } else {
        helper(str+")", left, right-1, res);
      }
    } else {
      if (left > right) {
        // wrong branch
        return;
      } else if (left == right) {
        helper(str+"(", left-1, right, res);
      } else {
        helper(str+"(", left-1, right, res);
        helper(str+")", left, right-1, res);
      }
    }
  }
};

class Solution1 {
 public:
  vector<string> generateParenthesis(int n) {
    if (n == 0) {
      return vector<string>();
    }
    vector<string> res;
    dfs("", n, n, res);
    return res;
  }

  void dfs(const string &str, int left, int right, vector<string> &res) {
    if (left == 0 && right == 0) {
      res.push_back(str);
      return;
    }

    if (left > right) {
      return;
    }

    if (left > 0) {
      dfs(str+"(", left-1, right, res);
    }

    if (right > 0) {
      dfs(str+")", left, right-1, res);
    }
  }
};

}

