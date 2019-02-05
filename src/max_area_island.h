// Go for your dream, Barney

// Get the max area of a island in an x-y matrix
// question: https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1034/

#ifndef LEETCODE_MAX_AREA_ISLAND_H__
#define LEETCODE_MAX_AREA_ISLAND_H__

#include <vector>
#include <math.h>

using namespace std;

int areaCounter(vector<vector<int> >&grid, int i, int j) {
  // set already search zone to 0
  if (i < 0 || j < 0 ||
      i >= grid.size() || j >= grid[0].size() ||
      grid[i][j] == 0) {
    return 0;
  }
  grid[i][j] = 0;

  return 1 + areaCounter(grid, i-1, j) + areaCounter(grid, i+1, j)
      + areaCounter(grid, i, j-1) + areaCounter(grid, i, j+1);

}

int maxAreaOfIsland(vector<vector<int> >& grid) {

  int maxc = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i].at(j)) {
        maxc = max(areaCounter(grid, i, j), maxc);
      }
    }
  }

  return maxc;
}



#endif // MAX_AREA_ISLAND_H

