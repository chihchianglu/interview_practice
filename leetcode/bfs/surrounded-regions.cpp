//
// Created by Lu, Chih-chiang on 2019-03-08.
//

/**
 * Surrounded Regions
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * Example:
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * Explanation:
 *
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are
 * not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border
 * will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
 */

#include <queue>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static void solve(std::vector<std::vector<char>> &board) {
    int rows = board.size(), cols = rows ? board[0].size() : 0;
    if (rows == 0 || cols == 0) {
      return;
    }
    std::queue<std::vector<int>> q;
    std::vector<int> dir_x = {-1, 0, 0, 1};
    std::vector<int> dir_y = {0, -1, 1, 0};

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (i != 0 && i != rows - 1 && j != 0 && j != cols - 1) {
          continue;
        } else if (board[i][j] != 'O') {
          continue;
        }
        q.push({i, j});
        while (!q.empty()) {
          int x = q.front()[0];
          int y = q.front()[1];
          board[x][y] = '$';
          q.pop();
          for (int k = 0; k < 4; ++k) {
            int neighbor_x = x + dir_x[k];
            int neighbor_y = y + dir_y[k];
            if (neighbor_x >= 0 && neighbor_x < rows && neighbor_y >= 0 && neighbor_y < cols
                && board[neighbor_x][neighbor_y] == 'O') {
              q.push({neighbor_x, neighbor_y});
              board[neighbor_x][neighbor_y] = '$';
            }
          }
        }
      }
    }
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == '$') {
          board[i][j] = 'O';
        }
      }
    }
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>>
      in = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
  std::vector<std::vector<char>>
      out = {{'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}};
  Solution::solve(in);
  if (in != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
