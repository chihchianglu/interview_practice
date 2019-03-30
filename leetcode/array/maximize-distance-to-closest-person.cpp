//
// Created by Lu, Chih-chiang on 2019-01-01.
//

/**
 * Maximize Distance to Closest Person
 *
 * In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.
 *
 * There is at least one empty seat, and at least one person sitting.
 *
 * Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
 *
 * Return that maximum distance to closest person.
 *
 * Example 1:
 *
 * Input: [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation:
 * If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 *
 * Example 2:
 *
 * Input: [1,0,0,0]
 * Output: 3
 * Explanation:
 * If Alex sits in the last seat, the closest person is 3 seats away.
 * This is the maximum distance possible, so the answer is 3.
 *
 * Note:
 *
 * - 1 <= seats.length <= 20000
 * - seats contains only 0s or 1s, at least one 0, and at least one 1.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  // Time: O(n), Space O(1)
  static int maxDistToClosest(std::vector<int> &seats) {
    int res = 0, prev = -1, n = seats.size();
    for (int i = 0; i < n; ++i) {
      if (seats[i]) {
        if (prev < 0) {
          res = i;
        } else {
          res = std::max(res, (i - prev) / 2);
        }
        prev = i;
      }
    }
    // 0 in the end
    res = std::max(res, n - prev - 1);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 0, 0, 0, 1, 0, 1};
  std::vector<int> vec2 = {1, 0, 0, 0};
  if (Solution::maxDistToClosest(vec1) != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::maxDistToClosest(vec2) != 3) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
