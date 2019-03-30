//
// Created by Lu, Chih-chiang on 2019-03-07.
//

/**
 * Word Search
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 *
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool backtracking(std::vector<std::vector<char>> &board, std::string word, int idx, int i, int j) {
    if (idx == word.size()) {
      return true;
    }
    int rows = board.size(), cols = board[0].size();
    if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != word[idx]) {
      return false;
    }
    auto c = board[i][j];
    board[i][j] = '#';
    bool res = backtracking(board, word, idx + 1, i - 1, j) || backtracking(board, word, idx + 1, i + 1, j)
        || backtracking(board, word, idx + 1, i, j - 1) || backtracking(board, word, idx + 1, i, j + 1);
    board[i][j] = c;
    return res;
  }
  static bool exist(std::vector<std::vector<char>> &board, std::string word) {
    int rows = board.size(), cols = rows > 0 ? board[0].size() : 0;
    if (rows == 0 || cols == 0) {
      return false;
    }
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (backtracking(board, word, 0, row, col)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  if (!Solution::exist(board, "ABCCED")) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::exist(board, "SEE")) {
    throw std::runtime_error("error 2");
  }
  if (Solution::exist(board, "ABCB")) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
