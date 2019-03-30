//
// Created by Lu, Chih-chiang on 2019-01-03.
//

/**
 * Pascal's Triangle
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 *
 * Example:
 *
 * Input: 5
 * Output:
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */


#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res(numRows, std::vector<int>());
    for (int i = 0; i < numRows; ++i) {
      res[i].resize(i + 1, 1);
      for (int j = 1; j < i; ++j) {
        res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> out = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
  if (Solution::generate(5) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
