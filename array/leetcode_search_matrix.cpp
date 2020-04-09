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
  bool search_matrix(vector<vector<int>> &matrix, int target) {
    // handle special situation
    if (matrix.empty()) return false;
    if (matrix[0].empty()) return false;
    if (matrix[0][0] > target) { return false; }
    if (matrix.back().back() < target) { return false; }

    int up = 0, down = matrix.size() - 1;
    if (down == 0) {
      return row_binary_search(matrix, target, 0);
    }
    while (down - up >= 1) {
      int mid = up + (down - up) / 2;
      if (matrix[mid][0] == target) {
        return true;
      } else if (matrix[mid][0] > target) {
        if (matrix[mid-1][0] == target) {
          return true;
        } else  if (matrix[mid-1][0] > target) {
          down = mid - 1;
        } else {
          up = mid - 1;
          down = mid;
          break;
        }
      } else {  // matrix[mid][0] < target
        if (matrix[mid+1][0] == target) {
          return true;
        } else if (matrix[mid+1][0] < target) {
          up = mid + 1;
        } else {
          up = mid;
          down = mid + 1;
          break;
        }
      }
    }
    return row_binary_search(matrix, target, up);
  }

  bool row_binary_search(vector<vector<int>> &matrix, int target, int row) {
    int left = 0;
    int right = matrix[row].size()-1;
    while (left <= right) {
      int mid = left + (right-left)/2;
      if (matrix[row][mid] == target) {
        return true;
      } else if (matrix[row][mid] > target) {
        right = mid - 1;;
      } else {
        left = mid + 1;
      }
    }
    return false;
  }
};



