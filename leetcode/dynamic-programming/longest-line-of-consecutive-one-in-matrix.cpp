//
// Created by Lu, Chih-chiang on 2019-03-16.
//

/**
 * Longest Line of Consecutive One in Matrix
 *
 * Given a 01 matrix M, find the longest line of consecutive one in the matrix.
 * The line could be horizontal, vertical, diagonal or anti-diagonal.
 *
 * Example:
 *
 * Input:
 * [[0,1,1,0],
 *  [0,1,1,0],
 *  [0,0,0,1]]
 * Output: 3
 *
 * Hint: The number of elements in the given matrix will not exceed 10,000.
 */

#include <vector>
#include <stdexcept>

// 我们可以考虑用DP解法来做，我们建立一个三维dp数组，其中dp[i][j][k]表示从开头遍历到数字nums[i][j]为止，第k种情况的连续1的个数，
// k的值为0，1，2，3，分别对应水平，竖直，对角线和逆对角线这四种情况。
// 之后就是更新dp数组的过程了，如果数字为0的情况直接跳过，然后水平方向就加上前一个的dp值，竖直方向加上上面一个数字的dp值，
// 对角线方向就加上右上方数字的dp值，逆对角线就加上左上方数字的dp值，然后每个值都用来更新结果res
class Solution {
 public:
  static int longestLine(std::vector<std::vector<int>> &M) {
    int rows = M.size(), cols = rows ? M[0].size() : 0, res = 0;
    if (rows == 0 || cols == 0) {
      return res;
    }
    std::vector<std::vector<std::vector<int>>> dp(rows, std::vector<std::vector<int>>(cols, std::vector<int>(4, 0)));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (M[i][j] == 1) {
          dp[i][j][0] = j > 0 ? dp[i][j - 1][0] + 1 : 1; // horizontal
          dp[i][j][1] = i > 0 ? dp[i - 1][j][1] + 1 : 1; // vertical
          dp[i][j][2] = i > 0 && j < cols - 1 ? dp[i - 1][j + 1][2] + 1 : 1; // diagnal
          dp[i][j][3] = i > 0 && j > 0 ? dp[i - 1][j - 1][3] + 1 : 1; // anti-diagnal
          res = std::max(res, std::max(std::max(std::max(dp[i][j][0], dp[i][j][1]), dp[i][j][2]), dp[i][j][3]));
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> matrix{{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}};
  if (Solution::longestLine(matrix) != 3) {
    throw std::runtime_error("error");
  }
  return 0;
}
