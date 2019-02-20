#include <iostream>

#include "src/longest_string_without_same.h"
#include "src/reverse_int.h"
#include "src/longest_common_prefix.h"
#include "src/s2_contain_s1.h"
#include "src/two_string_multip.h"
#include "src/reverse_string.h"
#include "src/restore_ip_address.h"
#include "src/three_sum.h"
#include "src/max_area_island.h"
#include "src/search_target_in_rotation_array.h"
#include "src/trape_water.h"
#include "src/list/list_handle.h"
#include "src/dynamic_plan/dynamic_plan.h"
#include "src/dynamic_plan/package_problem.h"

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

//  string s1 = "111111111111111";
//  vector<string> r1 = restoreIpAddresses(s1);

//  for (int i = 0; i < r1.size(); ++i) {
//    cout << r1[i] << '\t';
//  }
//  cout << endl;

//  vector<int> k;
//  k.push_back(-1);
//  k.push_back(0);
//  k.push_back(1);
//  k.push_back(2);
//  k.push_back(-1);
//  k.push_back(-4);
//  vector<vector<int> > r = threeSum(k);

//  vector<int> row;
//  row.push_back(0);
//  row.push_back(1);
//  vector<vector<int> >col;
//  col.push_back(row);
//  row.clear();
//  row.push_back(1);
//  row.push_back(1);
//  col.push_back(row);

//  int count = maxAreaOfIsland(col);

//  vector<int> k;
//  k.push_back(4);
//  k.push_back(5);
//  k.push_back(6);
//  k.push_back(7);
//  k.push_back(0);
//  k.push_back(1);
//  k.push_back(2);

//  int r = searchInRotationArray(k, 0);

//  vector<int> k;
//  k.push_back(0);
//  k.push_back(1);
//  k.push_back(0);
//  k.push_back(2);
//  k.push_back(1);
//  k.push_back(0);
//  k.push_back(1);
//  k.push_back(3);
//  k.push_back(2);
//  k.push_back(1);
//  k.push_back(2);
//  k.push_back(1);
//  int r = trap(k);

//  system("pause");

  ListTestMain();

  //dynamic_test_main();

  packageTestMain();

  return 0;
}
