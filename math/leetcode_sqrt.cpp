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
  int sqrt(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    int min_t = 0;
    int max_t = x;
    while (max_t - min_t > 1) {
      int mid = min_t + (max_t - min_t) / 2;
      int v = x / mid;
      if (v == mid) {
        return mid;
      } else if (v < mid) {
        int v2 = x/(mid-1);
        if (v2 == mid-1) {
          return mid-1;
        } else if (v2 < mid-1) {
          max_t = mid - 1;
        } else {
          min_t = mid - 1;
          max_t = mid;
          break;
        }
      } else {  // v < x
        int v2= x/(mid+1);
        if (v2 == mid+1) {
          return v2;
        } else if (v2 > mid+1) {
          min_t = mid + 1;
        } else {
          min_t = mid;
          max_t = mid + 1;
          break;
        }
      }
    }
    return min_t;
  }
};

int main() {
  MySolution solution;
  int re = solution.sqrt(2147395599);
  cout << re << endl;
}


