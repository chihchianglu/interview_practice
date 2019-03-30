//
// Created by Lu, Chih-chiang on 2019-01-27.
//

/**
 * For a undirected graph with tree characteristics, we can choose any node as the root.
 * The result graph is then a rooted tree. Among all possible rooted trees,
 * those with minimum height are called minimum height trees (MHTs). Given such a graph,
 * write a function to find all the MHTs and return a list of their root labels.
 *
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be given the
 * number n and a list of undirected edges (each edge is a pair of labels).
 *
 * You can assume that no duplicate edges will appear in edges. Since all edges are
 * undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 *
 * Example 1:
 *
 * Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 *
 *         0
 *         |
 *         1
 *        / \
 *       2   3
 *
 * return [1]
 *
 * Example 2:
 *
 * Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 *
 *      0  1  2
 *       \ | /
 *         3
 *         |
 *         4
 *         |
 *         5
 *
 * return [3, 4]
 *
 * Note:
 *
 * (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph
 * in which any two vertices are connected by exactly one path. In other words, any
 * connected graph without simple cycles is a tree.”
 *
 * (2) The height of a rooted tree is the number of edges on the longest downward path
 * between the root and a leaf.
 */

#include <queue>
#include <vector>
#include <stdexcept>
#include <unordered_set>

class Solution {
 public:
  static std::vector<int> findMinHeightTrees(int n, std::vector<std::pair<int, int>> &edges) {
    if (n == 1) {
      return {0};
    }
    std::vector<int> res;
    std::vector<std::unordered_set<int>> graph(n, std::unordered_set<int>());
    std::queue<int> q;

    for (auto &edge : edges) {
      graph[edge.first].insert(edge.second);
      graph[edge.second].insert(edge.first);
    }
    for (int i = 0; i < n; ++i) {
      if (graph[i].size() == 1) { // leaf
        q.push(i);
      }
    }
    // bfs
    while (n > 2) {
      int size = q.size();
      n -= size;
      for (int i = 0; i < size; ++i) {
        int val = q.front();
        q.pop();
        for (auto edge : graph[val]) {
          graph[edge].erase(val);
          if (graph[edge].size() == 1) {
            q.push(edge);
          }
        }
      }
    }
    while (!q.empty()) {
      res.push_back(q.front());
      q.pop();
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<int, int>> edge1 = {{1, 0}, {1, 2}, {1, 3}};
  std::vector<std::pair<int, int>> edge2 = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
  std::vector<int> out1 = {1};
  std::vector<int> out2 = {3, 4};

  if (Solution::findMinHeightTrees(4, edge1) != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findMinHeightTrees(6, edge2) != out2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
