//
// Created by Lu, Chih-chiang on 2019-01-25.
//

/**
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 * For example:
 *
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished
 * course 0. So it is possible.
 *
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have finished
 * course 0, and to take course 0 you should also have finished course 1. So it is
 * impossible.
 *
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
 * Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input prerequisites.
 * click to show more hints.
 *
 * Hints:
 * This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists,
 * no topological ordering exists and therefore it will be impossible to take all courses.
 *
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic
 * concepts of Topological Sort.
 * https://class.coursera.org/algo-003/lecture/52
 *
 * Topological sort could also be done via BFS.
 */

#include <queue>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool canFinish(int numCourses, std::vector<std::pair<int, int>> &prerequisites) {
    // graph of pre -> all nexts
    std::vector<std::vector<int>> graph(numCourses, std::vector<int>());
    // indegree calculation
    std::vector<int> degrees(numCourses, 0);
    for (auto &prerequisite : prerequisites) {
      graph[prerequisite.second].push_back(prerequisite.first);
      ++degrees[prerequisite.first];
    }
    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (degrees[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      --numCourses;
      for (auto neighbor : graph[cur]) {
        if (--degrees[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }
    return numCourses == 0; // cycle check
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<int, int>> prerequisites_1 = {{3, 2}, {2, 1}, {1, 0}};
  std::vector<std::pair<int, int>> prerequisites_2 = {{1, 0}, {0, 1}};

  if (!Solution::canFinish(4, prerequisites_1)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::canFinish(2, prerequisites_2)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
