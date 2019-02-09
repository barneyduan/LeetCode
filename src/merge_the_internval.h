// Fight for your dream, Barney

// Merge the internval
// question: https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1046/

#ifndef LEETCODE_MERGE_THE_INTERNVAL_H__
#define LEETCODE_MERGE_THE_INTERNVAL_H__

#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// Definition for an interval.
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals) {

  if (intervals.empty()) {
    return {};
  }

  sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});

  vector<Interval> result;
  Interval r = intervals[0];
  for (int i = 1; i < intervals.size(); ++i) {
    if (intervals[i].start > r.end) {
      result.push_back(r);
      r.start = intervals[i].start;
      r.end = intervals[i].end;
    } else {
      r.end = max(r.end, intervals[i].end);
    }
  }
  result.push_back(r);

  return result;
}
}

#endif // MERGE_THE_INTERNVAL_H

