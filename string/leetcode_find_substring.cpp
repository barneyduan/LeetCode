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
  vector<int> findSubstring(string s, vector<string> &words) {
    if (words.empty() || s.empty()) {
      return vector<int>();
    }
    unordered_map<string, int> map;
    // init the map
    for (auto &str : words) {
      if (map.find(str) != map.end()) {
        map[str] += 1;
      } else {
        map[str] = 1;
      }
    }
    int word_size = words[0].size();
    int str_size = s.size();
    int count = words.size();
    int j = 0;
    vector<int> res;
    for (int i = 0; i < str_size - word_size * count + 1; i++) {
      unordered_map<string, int> temp_map = map;
      for (j = 0; j < count; j++) {
        string sub_str = s.substr(i + word_size * j, word_size);
        if (temp_map.find(sub_str) != temp_map.end() && temp_map[sub_str] != 0) {
          temp_map[sub_str] -= 1;
        } else {
          break;
        }
      }
      if (j == count) {
        res.push_back(i);
      }
    }
    return res;
  }

};



