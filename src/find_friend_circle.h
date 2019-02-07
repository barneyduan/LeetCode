// Fight for your dream, Barney

// Find the connected components in a undirected graph
// question:https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1036/

#ifndef LEETCODE_FIND_FRIEND_CIRCLE_H__
#define LEETCODE_FIND_FRIEND_CIRCLE_H__

#include <vector>
#include <queue>

using namespace std;

void findCircleNumByDFS(vector<vector<int> >& M, int i, vector<bool> &visited) {

  visited[i] = true;
  for (int k = 0; k < M.size(); ++k) {
    if (!M[i][k] || visited[k]) continue;
    findCircleNumByDFS(M, k, visited);
  }
}

int findFriendCircleNum(vector<vector<int> >& M) {

  int count = 0;
  int n = M.size();
  vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (visited[i]) continue;
    findCircleNumByDFS(M, i, visited);
    ++count;
  }

  return count;
}



int findCircleNumByBFS(vector<vector<int> >& M) {

  int count = 0;
  int n = M.size();
  vector<bool> visited(n, false);
  queue<int> bfs_v;
  for (int i = 0; i < n; ++i) {
    if (visited[i]) continue;
    bfs_v.push(i);
    while (!bfs_v.empty()) {
      int t = bfs_v.front();
      bfs_v.pop();
      visited[t] = true;
      for (int j = 0; j < n; ++j) {
        if (!M[t][j] || visited[j]) {
          continue;
        }
        bfs_v.push(j);
      }
    }
    ++count;
  }

  return count;

}

#endif // FIND_FRIEND_CIRCLE_H

