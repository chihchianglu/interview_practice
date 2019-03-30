//
// Created by Lu, Chih-chiang on 2019-01-03.
//

/**
 * Pascal's Triangle II
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 *
 * Note that the row index starts from 0.
 *
 * Example:
 *
 * Input: 3
 * Output: [1,3,3,1]
 * Follow up:
 *
 * Could you optimize your algorithm to use only O(k) extra space?
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> getRow(int rowIndex) {
    std::vector<int> res(rowIndex + 1);
    res[0] = 1;
    for (int i = 1; i <= rowIndex; ++i) {
      for (int j = i; j >= 1; --j) {
        res[j] += res[j - 1];
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> out = {1, 3, 3, 1};
  if (Solution::getRow(3) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
