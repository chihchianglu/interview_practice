//
// Created by Lu, Chih-chiang on 2019-02-01.
//

/**
 * Lonely Pixel II
 *
 * Given a picture consisting of black and white pixels, and a positive integer N,
 * find the number of black pixels located at some specific row R and column C that align with all the following rules:
 *
 * 1. Row R and column C both contain exactly N black pixels.
 * 2. For all rows that have a black pixel at column C, they should be exactly the same as row R
 * The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels
 * respectively.
 *
 * Example:
 * Input:
 * [['W', 'B', 'W', 'B', 'B', 'W'],
 *  ['W', 'B', 'W', 'B', 'B', 'W'],
 *  ['W', 'B', 'W', 'B', 'B', 'W'],
 *  ['W', 'W', 'B', 'W', 'B', 'W']]
 *
 * N = 3
 * Output: 6
 * Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
 *         0    1    2    3    4    5         column index
 * 0    [['W', 'B', 'W', 'B', 'B', 'W'],
 * 1     ['W', 'B', 'W', 'B', 'B', 'W'],
 * 2     ['W', 'B', 'W', 'B', 'B', 'W'],
 * 3     ['W', 'W', 'B', 'W', 'B', 'W']]
 * row index
 *
 * Take 'B' at row R = 0 and column C = 1 as an example:
 * Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels.
 * Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.
 *
 * Note:
 * The range of width and height of the input 2D array is [1,200].
 */

#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  static int findBlackPixel(std::vector<std::vector<char>> &picture, int N) {
    int rows = picture.size(), cols = rows ? picture[0].size() : 0, res = 0;
    std::vector<int> col_b_count(cols, 0);
    std::unordered_map<std::string, int> m;
    if (rows == 0 || cols == 0) {
      return res;
    }
    // Step 1. Count how many 'B' in each row and column
    // and build the map of row key <=> pattern count when there is N 'B' in that row
    for (int i = 0; i < rows; ++i) {
      int count = 0;
      for (int j = 0; j < cols; ++j) {
        if (picture[i][j] == 'B') {
          ++col_b_count[j];
          ++count;
        }
      }
      if (count == N) {
        ++m[std::string(picture[i].begin(), picture[i].end())];
      }
    }
    for (auto &a : m) {
      if (a.second != N) {
        continue;
      }
      for (int i = 0; i < cols; ++i) {
        if (a.first[i] == 'B' && col_b_count[i] == N) {
          res += N;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>> vec =
      {{'W', 'B', 'W', 'B', 'B', 'W'}, {'W', 'B', 'W', 'B', 'B', 'W'}, {'W', 'B', 'W', 'B', 'B', 'W'},
       {'W', 'W', 'B', 'W', 'B', 'W'}};
  if (Solution::findBlackPixel(vec, 3) != 6) {
    throw std::runtime_error("error");
  }
  return 0;
}
