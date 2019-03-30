//
// Created by Lu, Chih-chiang on 2019-01-27.
//

/**
 * Redundant Connection
 *
 * In this problem, a tree is an undirected graph that is connected and has no cycles.
 *
 * The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N),
 * with one additional edge added. The added edge has two different vertices chosen from 1 to N,
 * and was not an edge that already existed.
 *
 * The resulting graph is given as a 2D-array of edges. Each element of edges is a pair {u, v} with u < v,
 * that represents an undirected edge connecting nodes u and v.
 *
 * Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple
 * answers, return the answer that occurs last in the given 2D-array. The answer edge {u, v} should be in the
 * same format, with u < v.
 *
 * Example 1:
 * Input: {{1,2}, {1,3}, {2,3}}
 * Output: {2,3}
 *
 * Explanation: The given undirected graph will be like this:
 *
 *   1
 *  / \
 * 2 - 3
 *
 *  Example 2:
 * Input: {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}}
 * Output: {1,4}
 *
 * Explanation: The given undirected graph will be like this:
 *
 * 5 - 1 - 2
 *     |   |
 *     4 - 3
 *
 * Note:
 * The size of the input 2D-array will be between 3 and 1000.
 * Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
 *
 * Update (2017-09-26):
 * We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph.
 * For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.
 */

#include <vector>
#include <stdexcept>

// 这道题给我们了一个无向图，让我们删掉组成环的最后一条边，其实这道题跟之前那道Graph Valid Tree基本没什么区别，三种解法都基本相同。
// 博主觉得老题稍微变一下就是一道新题，而onsite遇到原题的概率很小，大多情况下都会稍稍变一下，所以举一反三的能力真的很重要，
// 要完全吃透一道题也不太容易，需要多下功夫。

// 其实这道题最好的解法使用Union Find来做，论坛上清一色的都是用这种解法来做的，
// 其实Union Find的核心思想并不是很难理解，首先我们建立一个长度为(n+1)的数组root，由于这道题并没有明确的说明n是多少，
// 只是说了输入的二位数组的长度不超过1000，那么n绝对不会超过2000，我们加1的原因是由于结点值是从1开始的，而数组是从0开始的，
// 我们懒得转换了，就多加一位得了。我们将这个数组都初始化为-1，有些人喜欢初始化为i，都可以。开始表示每个结点都是一个单独的组，
// 所谓的Union Find就是要让结点之间建立关联，比如若root[1] = 2，就表示结点1和结点2是相连的，root[2] = 3表示结点2和结点3是相连的，
// 如果我们此时新加一条边[1, 3]的话，我们通过root[1]得到2，再通过root[2]得到3，说明结点1有另一条路径能到结点3，这样就说明环是存在的；
// 如果没有这条路径，那么我们要将结点1和结点3关联起来，让root[1] = 3即可
class Solution {
 public:
  static int union_find(std::vector<int> &root, int i) {
    while (root[i] != 0) {
      i = root[i];
    }
    return i;
  }
  static std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges) {
    std::vector<int> root(2001, 0);
    for (auto edge : edges) {
      int parent_a = union_find(root, edge[0]);
      int parent_b = union_find(root, edge[1]);
      if (parent_a == parent_b) {
        return edge;
      }
      root[parent_a] = parent_b;
    }
    return {};
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> edges =
      {{16, 25}, {7, 9}, {3, 24}, {10, 20}, {15, 24}, {2, 8}, {19, 21}, {2, 15}, {13, 20}, {5, 21}, {7, 11}, {6, 23},
       {7, 16}, {1, 8}, {17, 20}, {4, 19}, {11, 22}, {5, 11}, {1, 16}, {14, 20}, {1, 4}, {22, 23}, {12, 20}, {15, 18},
       {12, 16}};
  std::vector<int> out = {1, 4};
  if (Solution::findRedundantConnection(edges) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
