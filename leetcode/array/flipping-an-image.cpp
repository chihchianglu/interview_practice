//
// Created by Lu, Chih-chiang on 2018-12-30.
//

/**
 * Flipping an Image
 *
 * Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
 *
 * To flip an image horizontally means that each row of the image is reversed.
 * For example, flipping [1, 1, 0]  * horizontally results in [0, 1, 1].
 *
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
 * For example, inverting [0, 1, 1]  * results in [1, 0, 0].
 *
 * Example 1:
 *
 * Input: [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 *
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 * Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 *
 * Example 2:
 *
 * Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 *
 * Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 * Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 *
 * Notes:
 *
 * 1 <= A.length = A[0].length <= 20
 * 0 <= A[i][j] <= 1
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>> &A) {
    for (auto &row : A) {
      int n = row.size();
      for (int i = 0; i * 2 < n; ++i) {
        if (row[i] == row[n - i - 1]) {
          row[i] = row[n - i - 1] ^= 1; // xor 1 results in opposite value
          // 0 ^ 0 = 0
          // 0 ^ 1 = 1
          // 1 ^ 0 = 1
          // 1 ^ 1 = 0
        }
      }
    }
    return A;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec1 = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
  std::vector<std::vector<int>> out1 = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  std::vector<std::vector<int>> vec2 = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};
  std::vector<std::vector<int>> out2 = {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}};
  if (Solution::flipAndInvertImage(vec1) != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::flipAndInvertImage(vec2) != out2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
