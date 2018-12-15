#include <iostream>

#include "src/longest_string_without_same.h"

using namespace std;

int main(int argc, char *argv[])
{

  string test1 = "abc";

  cout << lengthOfLongestSubstringImprove(test1) << endl;

  string test2 = "abcded";

  cout << lengthOfLongestSubstringImprove(test2) << endl;

  system("pause");

  return 0;
}
