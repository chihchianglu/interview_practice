//
// Created by Lu, Chih-chiang on 2019-01-02.
//

/**
 * Number of Boomerangs
 *
 * Given n points in the plane that are all pairwise distinct,
 * a "boomerang" is a tuple of points (i, j, k) such that
 * the distance between i and j equals the distance between i and k (the order of the tuple matters).
 *
 * Find the number of boomerangs.
 * You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
 *
 * Example:
 * Input:
 * [[0,0],[1,0],[2,0]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 */

#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  // 直線距離公式: (x2 - x1)^2 + (y2 - y1)^2 開根號
  static int distance(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    return x * x + y * y;
  }
  static int numberOfBoomerangs(std::vector<std::pair<int, int>> &points) {
    int res = 0, n = points.size();
    for (int i = 0; i < n; ++i) {
      std::unordered_map<int, int> map;
      for (int j = 0; j < n; ++j) {
        if (i == j) {
          continue;
        }
        ++map[distance(points[i], points[j])];
      }
      for (auto &m : map) {
        res += m.second * (m.second - 1); // permutations P(n, 2) = n * (n - 1)
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::pair<int, int>> vec = {{0, 0}, {1, 0}, {2, 0}};
  if (Solution::numberOfBoomerangs(vec) != 2) {
    throw std::runtime_error("error");
  }
  return 0;
}
