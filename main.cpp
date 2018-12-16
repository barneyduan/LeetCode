#include <iostream>

#include "src/longest_string_without_same.h"
#include "src/reverse_int.h"

using namespace std;

int main(int argc, char *argv[])
{

  string test1 = "abc";

  cout << lengthOfLongestSubstringImprove(test1) << endl;

  string test2 = "abcded";

  cout << lengthOfLongestSubstringImprove(test2) << endl;

  int x1 = 1463847412;

  cout << reverse(x1) << endl;

  int x2 = 120;
  cout << reverse(x2) << endl;

  int x3 = 1534236469;
  cout << reverse(x3) << endl;

  system("pause");

  return 0;
}
