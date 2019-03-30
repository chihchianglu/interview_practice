//
// Created by Lu, Chih-chiang on 2019-01-25.
//

/**
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
 * which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, return the ordering of courses
 * you should take to finish all courses.
 *
 * There may be multiple correct orders, you just need to return one of them. If it is impossible to
 * finish all courses, return an empty array.
 *
 * For example:
 *
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the
 * correct course order is [0,1]
 *
 * 4, [[1,0],[2,0],[3,1],[3,2]]
 * There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and
 * 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is
 * [0,1,2,3]. Another correct ordering is[0,2,1,3].
 *
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more
 * about how a graph is represented.
 * You may assume that there are no duplicate edges in the input prerequisites.
 * click to show more hints.
 *
 * Hints:
 * This problem is equivalent to finding the topological order in a directed graph. If a cycle exists,
 * no topological ordering exists and therefore it will be impossible to take all courses.
 *
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts
 * of Topological Sort.
 *
 * Topological sort could also be done via BFS.
 */

#include <queue>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>> &prerequisites) {
    std::vector<int> res;
    std::vector<std::vector<int>> graph(numCourses, std::vector<int>());
    std::vector<int> degrees(numCourses, 0);
    for (auto &prerequisite : prerequisites) {
      graph[prerequisite.second].push_back(prerequisite.first);
      ++degrees[prerequisite.first];
    }

    std::queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (!degrees[i]) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      res.push_back(cur);
      for (auto next : graph[cur]) {
        if (--degrees[next] == 0) {
          q.push(next);
        }
      }
    }
    if (res.size() != numCourses) {
      res.clear();
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<int, int>> prerequisites_1 = {{3, 2}, {2, 1}, {1, 0}};
  std::vector<std::pair<int, int>> prerequisites_2 = {{1, 0}, {0, 1}};
  std::vector<int> out_1 = {0, 1, 2, 3};
  std::vector<int> out_2;

  if (Solution::findOrder(4, prerequisites_1) != out_1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findOrder(2, prerequisites_2) != out_2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
