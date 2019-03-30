//
// Created by Lu, Chih-chiang on 2019-01-05.
//

/**
 * Spiral Matrix-ii
 *
 * Given a positive integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
 *
 * Example:
 * Input: 3
 * Output:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
    int up = 0, down = n - 1, left = 0, right = n - 1, val = 1;

    while (true) {
      // left -> right
      for (int i = left; i <= right; ++i) {
        res[up][i] = val++;
      }
      if (++up > down) {
        break;
      }
      // up -> down
      for (int i = up; i <= down; ++i) {
        res[i][right] = val++;
      }
      if (--right < left) {
        break;
      }
      // right -> left
      for (int i = right; i >= left; --i) {
        res[down][i] = val++;
      }
      if (--down < up) {
        break;
      }
      // down -> up
      for (int i = down; i >= up; --i) {
        res[i][left] = val++;
      }
      if (++left > right) {
        break;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> out = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
  if (Solution::generateMatrix(3) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
