//
// Created by Lu, Chih-chiang on 2019-01-27.
//

/**
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
 * write a function to check whether these edges make up a valid tree.
 *
 * For example:
 *
 * Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
 *
 * Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
 *
 * Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected,
 * [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 *
 * The key idea is to check whether the undirected graph has cycle and make sure all vertices are connected
 */

#include <queue>
#include <vector>
#include <stdexcept>
#include <unordered_set>

class Solution {
 public:
  // bfs
  static bool validTree(int n, std::vector<std::pair<int, int>> &edges) {
    std::vector<std::unordered_set<int>> graph(n, std::unordered_set<int>());
    std::unordered_set<int> out{0};
    std::queue<int> q{{0}};
    for (auto &edge : edges) {
      graph[edge.first].insert(edge.second);
      graph[edge.second].insert(edge.first);
    }

    while (!q.empty()) {
      int val = q.front();
      q.pop();
      for (auto &edge : graph[val]) {
        if (out.count(edge)) {
          return false; // cycle
        }
        out.insert(edge);
        q.push(edge);
        graph[edge].erase(val);
      }
    }
    return out.size() == n;
  }

  // union find - focus on this route
  static int union_find(std::vector<int> &roots, int i) {
    while (roots[i] != -1) {
      i = roots[i];
    }
    return i;
  }
  static bool validTree_union_find(int n, std::vector<std::pair<int, int>> &edges) {
    std::vector<int> roots(n, -1);
    for (auto &edge : edges) {
      int parent_a = union_find(roots, edge.first);
      int parent_b = union_find(roots, edge.second);
      if (parent_a == parent_b) {
        return false;
      }
      roots[parent_a] = parent_b;
    }
    return edges.size() == n - 1; // tree has to be connected
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<int, int>> vec1 = {{0, 1}, {2, 0}, {0, 3}, {1, 4}};
  std::vector<std::pair<int, int>> vec2 = {{0, 1}, {2, 1}, {2, 3}, {1, 3}, {1, 4}};
  if (!Solution::validTree(5, vec1)) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::validTree_union_find(5, vec1)) {
    throw std::runtime_error("error 2");
  }
  if (Solution::validTree(5, vec2)) {
    throw std::runtime_error("error 3");
  }
  if (Solution::validTree_union_find(5, vec2)) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
