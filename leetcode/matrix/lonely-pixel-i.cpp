//
// Created by Lu, Chih-chiang on 2019-02-01.
//

/**
 * Lonely Pixel I
 *
 * Given a picture consisting of black and white pixels, find the number of black lonely pixels.
 *
 * The picture is represented by a 2D char array consisting of 'B' and 'W',
 * which means black and white pixels respectively.
 *
 * A black lonely pixel is character 'B' that located at a specific position where the same row and
 * same column don't have any other black pixels.
 *
 * Example:
 *
 * Input:
 * [['W', 'W', 'B'],
 *  ['W', 'B', 'W'],
 *  ['B', 'W', 'W']]
 *
 * Output: 3
 *
 * Explanation: All the three 'B's are black lonely pixels.
 *
 * Note:
 * The range of width and height of the input 2D array is [1,500].
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int findLonelyPixel(std::vector<std::vector<char>> &picture) {
    int rows = picture.size(), cols = rows ? picture[0].size() : 0, res = 0;
    std::vector<int> row_b_count(rows, 0), col_b_count(cols, 0);
    if (rows == 0 || cols == 0) {
      return res;
    }
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (picture[i][j] == 'B') {
          ++row_b_count[i];
          ++col_b_count[j];
        }
      }
    }
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (picture[i][j] == 'B') {
          if (row_b_count[i] == 1 && col_b_count[j] == 1) {
            ++res;
          }
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>> vec = {{'W', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'W'}};
  if (Solution::findLonelyPixel(vec) != 3) {
    throw std::runtime_error("error");
  }
  return 0;
}
