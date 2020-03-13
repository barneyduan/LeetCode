// Practice make perfect :)
// Duan Lian

/*
 * I meet a question, erase from an unordered_map cause core-dump, Let's see how
 * this dumb bug I made...
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  std::unordered_map<int, int> map_;
  map_[1] = 1;
  map_[2] = 2;

  for (auto &it : map_) {
    map_.erase(it.first); // this is so ugly write......
  }

  return 0;
}


/*
 * Why line 20 cause fatal error, because for_range is a template writting.
 * for (auto it : map_) is like:
 * ----------------------------
 *  auto begin = begin_iterator;
 *  auto end = end_iterator;
 *  for (auto it = begin; it != end; it++) {
 *    ....
 *  }
 *
 *  And, the unordered_map.erase() will invalidate the input iterator...
 *  from cppplusplus.com:
 *  -----------------------------------
 *  References and iterators to the erased elements are invalidated.
 *  Other iterators and references are not invalidated.
 *  ------------------------------------
 *  so, when erase it.first(), and it is invalid as an iterator, and it will
 *  be wrong to seek next iterator...
 *
 *  so...what's the safe write mode:
 * */


int main_safe() {
  std::unordered_map<int, int> map_;
  map_[1] = 1;
  map_[2] = 2;
  for (auto it = map_.begin(); it != map_.end();) {
    map_.erase(it++); // not ++it....
  }
  return 0;
}

/*

int& operator++() {
  *this += 1;
  return *this; // ++i return it self
}

const int operator++(int) {
  int old_value = *this;
  *this += 1;
  return old_value; //i++ return a temp value
}

*/

/*
 * So, map_.erase(it++), the real it will increase, and return a copied old
 * iterator to erase(), even if erase destroy this iterator, it will seek the
 * correct next iterator.
 */


