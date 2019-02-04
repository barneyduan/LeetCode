#include <iostream>

#include "src/longest_string_without_same.h"
#include "src/reverse_int.h"
#include "src/longest_common_prefix.h"
#include "src/s2_contain_s1.h"
#include "src/two_string_multip.h"
#include "src/reverse_string.h"
#include "src/restore_ip_address.h"

using namespace std;

int main(int argc, char *argv[])
{

//  string test1 = "abc";

//  cout << lengthOfLongestSubstringImprove(test1) << endl;

//  string test2 = "abcded";

//  cout << lengthOfLongestSubstringImprove(test2) << endl;

//  int x1 = 1463847412;

//  cout << reverse(x1) << endl;

//  int x2 = 120;
//  cout << reverse(x2) << endl;

//  int x3 = 1534236469;
//  cout << reverse(x3) << endl;

//  vector<string> test3;
//  test3.push_back("dog");
//  test3.push_back("racerar");
//  test3.push_back("car");

//  cout << longestCommonPrefix(test3) << endl;

//  string test4 = "abb";
//  vector<string> ans;
//  createPermutation(test4, ans);

//  string test5 = "123";
//  string test6 = "456";
//  cout << multiply(test5, test6) << endl;

//  string s1 = "ab";
//  string s2 = "eibaooo";
//  cout << checkInclusion(s1, s2) << endl;

//  string s1 = "the sky is blue";
//  reverseWords(s1);

//  string s2 = "a";
//  reverseWords(s2);

//  string s3 = "1 ";
//  reverseWords(s3);

//  cout << s3 << endl;

  string s1 = "111111111111111";
  vector<string> r1 = restoreIpAddresses(s1);

  for (int i = 0; i < r1.size(); ++i) {
    cout << r1[i] << '\t';
  }
  cout << endl;

  system("pause");

  return 0;
}
