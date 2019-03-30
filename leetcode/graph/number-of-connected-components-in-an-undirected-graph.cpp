//
// Created by Lu, Chih-chiang on 2019-01-27.
//

/**
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
 * write a function to find the number of connected components in an undirected graph.
 *
 * Example 1:
 *
 *      0          3
 *      |          |
 *      1 --- 2    4
 * Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
 *
 * Example 2:
 *
 *      0           4
 *      |           |
 *      1 --- 2 --- 3
 * Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
 *
 * Note:
 * You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1]
 * is the same as [1, 0] and thus will not appear together in edges.
 */

#include <queue>
#include <vector>
#include <stdexcept>
#include <unordered_set>
#include <unordered_map>

class Solution {
 public:
  // BFS
  static int countComponents(int n, std::vector<std::pair<int, int>> &edges) {
    std::unordered_map<int, std::vector<int>> graph;
    std::vector<bool> visit(n, 0);
    int res = 0;
    std::queue<int> q;

    for (auto &edge : edges) {
      graph[edge.first].push_back(edge.second);
      graph[edge.second].push_back(edge.first);
    }

    for (int i = 0; i < n; ++i) {
      if (visit[i]) {
        continue;
      }
      visit[i] = 1;
      q.push(i);
      res++;
      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto neighbor : graph[cur]) {
          if (!visit[neighbor]) {
            q.push(neighbor);
            visit[neighbor] = 1;
          }
        }
      }
    }
    return res;
  }

  // union-find - focus on this route
  static int union_find(std::vector<int> &root, int i) {
    while (root[i] != i) {
      i = root[i];
    }
    return i;
  }
  static int countComponents_union_find(int n, std::vector<std::pair<int, int>> &edges) {
    int res = n;
    std::vector<int> root(n, 0);
    for (int i = 0; i < n; ++i) {
      root[i] = i;
    }
    for (auto &edge : edges) {
      int parent_a = union_find(root, edge.first);
      int parent_b = union_find(root, edge.second);
      if (parent_a != parent_b) {
        --res;
        root[parent_a] = parent_b;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<int, int>> edge1 = {{0, 1}, {1, 2}, {3, 4}};
  std::vector<std::pair<int, int>> edge2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
  if (Solution::countComponents(5, edge1) != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::countComponents_union_find(5, edge2) != 1) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
