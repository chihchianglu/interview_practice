//
// Created by Lu, Chih-chiang on 2019-02-01.
//

/**
 * Diagonal Traverse
 *
 * Given a matrix of M x N elements (M rows, N columns),
 * return all elements of the matrix in diagonal order as shown in the below image.
 *
 * Example:
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 *
 * Output:  [1,2,4,7,5,3,6,8,9]
 */

#include <vector>
#include <stdexcept>

// only 2 directions, right+up or left+down
// need to handle "row >= rows" && "col >= cols" cases, then "row < 0" && "col < 0"
class Solution {
 public:
  static std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
    int row = 0, col = 0, dir = 0;
    std::vector<int> res;
    std::vector<std::vector<int>> direction = {{-1, 1}, {1, -1}}; // up, down
    if (rows == 0 || cols == 0) {
      return res;
    }
    for (int i = 0; i < rows * cols; ++i) {
      res.push_back(matrix[row][col]);
      row += direction[dir][0], col += direction[dir][1];
      if (row >= rows) { // go up now
        row = rows - 1, col += 2, dir = 1 - dir;
      }
      if (col >= cols) { // go down now
        col = cols - 1, row += 2, dir = 1 - dir;
      }
      if (row < 0) { // go down now
        row = 0, dir = 1 - dir;
      }
      if (col < 0) { // go up now
        col = 0, dir = 1 - dir;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<int> out = {1, 2, 4, 7, 5, 3, 6, 8, 9};
  if (Solution::findDiagonalOrder(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
