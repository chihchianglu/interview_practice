//
// Created by Lu, Chih-chiang on 2019-02-01.
//

/**
 * Sparse Matrix Multiplication
 *
 * Given two sparse matrices A and B, return the result of AB.
 *
 * You may assume that A's column number is equal to B's row number.
 *
 * Example:
 *
 * Input:
 *
 * A = [
 *   [ 1, 0, 0],
 *   [-1, 0, 3]
 * ]
 *
 * B = [
 *   [ 7, 0, 0 ],
 *   [ 0, 0, 0 ],
 *   [ 0, 0, 1 ]
 * ]
 *
 * Output:
 *
 *      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
 * AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
 *                   | 0 0 1 |
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<std::vector<int>> multiply(std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B) {
    std::vector<std::vector<int>> res(A.size(), std::vector<int>(B[0].size(), 0));
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < A[0].size(); ++j) {
        if (A[i][j]) {
          for (int k = 0; k < B[0].size(); ++k) {
            if (B[j][k]) {
              res[i][k] += A[i][j] * B[j][k];
            }
          }
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> A = {{1, 0, 0}, {-1, 0, 3}};
  std::vector<std::vector<int>> B = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};
  std::vector<std::vector<int>> out = {{7, 0, 0}, {-7, 0, 3}};
  if (Solution::multiply(A, B) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
