//
// Created by Lu, Chih-chiang on 2019-01-27.
//

/**
 * Possible Bipartition
 *
 * Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
 * Each person may dislike some other people, and they should not go into the same group.
 * Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
 * Return true if and only if it is possible to split everyone into two groups in this way.
 *
 * Example 1:
 * Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: group1 [1,4], group2 [2,3]
 *
 * Example 2:
 * Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 *
 * Example 3:
 * Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * Output: false
 *
 * Note:
 * 1 <= N <= 2000
 * 0 <= dislikes.length <= 10000
 * 1 <= dislikes[i][j] <= N
 * dislikes[i][0] < dislikes[i][1]
 * There does not exist i != j for which dislikes[i] == dislikes[j].
 */

#include <queue>
#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  // BFS
  static bool possibleBipartition(int N, std::vector<std::vector<int>> &dislikes) {
    std::vector<std::vector<int>> mapping(N + 1);
    for (auto &dislike : dislikes) {
      mapping[dislike[0]].push_back(dislike[1]);
      mapping[dislike[1]].push_back(dislike[0]);
    }
    std::vector<int> colors(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      if (colors[i]) {
        continue;
      }
      colors[i] = 1;
      std::queue<int> q{{i}};
      while (!q.empty()) {
        int val = q.front();
        q.pop();
        for (auto cur : mapping[val]) {
          if (colors[cur] == colors[val]) {
            return false;
          } else if (!colors[cur]) {
            colors[cur] = -colors[val];
            q.push(cur);
          }
        }
      }
    }
    return true;
  }

  // union find - focus on this route
  static int union_find(std::vector<int> &root, int i) {
    while (root[i] != i) {
      i = root[i];
    }
    return i;
  }
  static bool possibleBipartition_union_find(int N, std::vector<std::vector<int>> &dislikes) {
    std::unordered_map<int, std::vector<int>> mapping;
    for (auto dislike : dislikes) {
      mapping[dislike[0]].push_back(dislike[1]);
      mapping[dislike[1]].push_back(dislike[0]);
    }
    std::vector<int> root(N + 1);
    for (int i = 1; i <= N; ++i) {
      root[i] = i;
    }
    for (int i = 1; i <= N; ++i) {
      if (!mapping.count(i)) {
        continue;
      }

      // similar to is-graph-bipartite
      int parent_a = union_find(root, i);
      int parent_b = union_find(root, mapping[i][0]);
      if (parent_a == parent_b) {
        return false;
      }
      for (int j = 1; j < mapping[i].size(); ++j) {
        int parent_c = union_find(root, mapping[i][j]);
        if (parent_a == parent_c) {
          return false;
        }
        root[parent_c] = parent_b;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec1 = {{1, 2}, {1, 3}, {2, 4}};
  std::vector<std::vector<int>> vec2 = {{1, 2}, {1, 3}, {2, 3}};
  std::vector<std::vector<int>> vec3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};

  if (!Solution::possibleBipartition(4, vec1)) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::possibleBipartition_union_find(4, vec1)) {
    throw std::runtime_error("error 2");
  }
  if (Solution::possibleBipartition(3, vec2)) {
    throw std::runtime_error("error 3");
  }
  if (Solution::possibleBipartition_union_find(3, vec2)) {
    throw std::runtime_error("error 4");
  }
  if (Solution::possibleBipartition(5, vec3)) {
    throw std::runtime_error("error 5");
  }
  if (Solution::possibleBipartition_union_find(5, vec3)) {
    throw std::runtime_error("error 6");
  }
  return 0;
}
