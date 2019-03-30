//
// Created by Lu, Chih-chiang on 2019-01-27.
//

/**
 * Is Graph Bipartite?
 *
 * Given an undirected graph, return true if and only if it is bipartite.
 *
 * Recall that a graph is bipartite if we can split it's set of nodes into two
 * independent subsets A and B such that every edge in the graph has one node in
 * A and another node in B.
 *
 * The graph is given in the following form: graph[i] is a list of indexes j for
 * which the edge between nodes i and j exists.  Each node is an integer between
 * 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i]
 * does not contain i, and it doesn't contain any element twice.
 *
 * Example 1:
 *
 * Input: [[1,3], [0,2], [1,3], [0,2]]
 * Output: true
 *
 * Explanation:
 *
 * The graph looks like this:
 *
 * 0----1
 * |    |
 * |    |
 * 3----2
 *
 * We can divide the vertices into two groups: {0, 2} and {1, 3}.
 *
 * Example 2:
 *
 * Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
 * Output: false
 *
 * Explanation:
 *
 * The graph looks like this:
 *
 * 0----1
 * | \  |
 * |  \ |
 * 3----2
 *
 * We cannot find a way to divide the set of nodes into two independent subsets.
 *
 * Note:
 *
 * graph will have length in range [1, 100].
 * graph[i] will contain integers in range [0, graph.length - 1].
 * graph[i] will not contain i or duplicate values.
 * The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
 */

#include <queue>
#include <vector>
#include <stdexcept>

// 输入数组中的graph[i]，表示顶点i所有相邻的顶点，比如对于例子1来说，顶点0和顶点1，3相连，顶点1和顶点0，2相连，顶点2和结点1，3相连，
// 顶点3和顶点0，2相连。这道题让我们验证给定的图是否是二分图，所谓二分图，就是可以将图中的所有顶点分成两个不相交的集合，
// 使得同一个集合的顶点不相连。为了验证是否有这样的两个不相交的集合存在，我们采用一种很机智的染色法，
// 大体上的思路是要将相连的两个顶点染成不同的颜色，一旦在染的过程中发现有两连的两个顶点已经被染成相同的颜色，说明不是二分图。
// 这里我们使用两种颜色，分别用1和-1来表示，初始时每个顶点用0表示未染色，遍历整个顶点，如果未被染色，则先染色为1，
// 然后使用BFS进行遍历，将当前顶点放入队列queue中，然后while循环queue不为空，取出队首元素，遍历其所有相邻的顶点，
// 如果相邻顶点未被染色，则染成和当前顶点相反的颜色，然后把相邻顶点加入queue中，否则如果当前顶点和相邻顶点颜色相同，
// 直接返回false，循环退出后返回true
class Solution {
 public:
  // bfs
  static bool isBipartite(std::vector<std::vector<int>> &graph) {
    std::vector<int> colors(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
      if (colors[i] != 0) {
        continue;
      }
      colors[i] = 1;
      std::queue<int> q{{i}};
      while (!q.empty()) {
        int val = q.front();
        q.pop();
        for (auto edge : graph[val]) {
          if (colors[edge] == colors[val]) {
            return false;
          } else if (!colors[edge]) {
            colors[edge] = -colors[val];
            q.push(edge);
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
  static bool isBipartite_union_find(std::vector<std::vector<int>> &graph) {
    std::vector<int> root(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
      root[i] = i;
    }
    for (int i = 0; i < graph.size(); ++i) {
      if (graph[i].empty()) {
        continue;
      }
      int parent_a = union_find(root, i);
      int parent_b = union_find(root, graph[i][0]);
      if (parent_a == parent_b) {
        return false;
      }
      for (int j = 1; j < graph[i].size(); ++j) {
        int parent_c = union_find(root, graph[i][j]);
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
  std::vector<std::vector<int>> vec1 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  std::vector<std::vector<int>> vec2 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  if (!Solution::isBipartite(vec1)) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::isBipartite_union_find(vec1)) {
    throw std::runtime_error("error 2");
  }
  if (Solution::isBipartite(vec2)) {
    throw std::runtime_error("error 3");
  }
  if (Solution::isBipartite_union_find(vec2)) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
