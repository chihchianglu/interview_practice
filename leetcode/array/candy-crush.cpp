//
// Created by Lu, Chih-chiang on 2018-12-27.
//

/**
 * Candy Crush
 *
 * This question is about implementing a basic elimination algorithm for Candy Crush.
 *
 * Given a 2D integer array board representing the grid of candy, different positive integers board[i][j]
 * represent different types of candies. A value of board[i][j] = 0 represents that the cell at position (i, j)
 * is empty. The given board represents the state of the game following the player's move.
 *
 * Now, you need to restore the board to a stable state by crushing candies according to the following rules:
 *
 * If three or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the
 * same time - these positions become empty.
 *
 * After crushing all candies simultaneously, if an empty space on the board has candies on top of itself,
 * then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop
 * outside the top boundary.)
 *
 * After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
 *
 * If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
 * You need to perform the above rules until the board becomes stable, then return the current board.
 *
 * Note:
 * The length of board will be in the range [3, 50].
 * The length of board[i] will be in the range [3, 50].
 * Each board[i][j] will initially start as an integer in the range [1, 2000].
 */

#include <cmath>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<std::vector<int>> candyCrush(std::vector<std::vector<int>> &board) {
    bool run = true;
    while (run) {
      run = false;
      int rows = board.size(), cols = board[0].size();

      // horizontal crashing
      for (int row = 0; row < rows; row++) {
        for (int col = 0; col + 2 < cols; col++) {
          int &v1 = board[row][col];
          int &v2 = board[row][col + 1];
          int &v3 = board[row][col + 2];

          int abs_v1 = std::abs(v1);
          if (abs_v1 && abs_v1 == std::abs(v2) && abs_v1 == std::abs(v3)) {
            v1 = v2 = v3 = -abs_v1;
            run = true;
          }
        }
      }

      // vertical crashing
      for (int col = 0; col < cols; col++) {
        for (int row = 0; row + 2 < rows; row++) {
          int &v1 = board[row][col];
          int &v2 = board[row + 1][col];
          int &v3 = board[row + 2][col];

          int abs_v1 = std::abs(v1);
          if (abs_v1 && abs_v1 == std::abs(v2) && abs_v1 == std::abs(v3)) {
            v1 = v2 = v3 = -abs_v1;
            run = true;
          }
        }
      }

      // drop handling
      for (int col = 0; col < cols; col++) {
        int drop_row = rows - 1;
        for (int row = rows - 1; row >= 0; row--) {
          if (board[row][col] >= 0) {
            board[drop_row--][col] = board[row][col];
          }
        }
        for (int row = drop_row; row >= 0; row--) {
          board[row][col] = 0;
        }
      }
    }
    return board;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> in =
      {{110, 5, 112, 113, 114}, {210, 211, 5, 213, 214}, {310, 311, 3, 313, 314}, {410, 411, 412, 5, 414},
       {5, 1, 512, 3, 3}, {610, 4, 1, 613, 614}, {710, 1, 2, 713, 714}, {810, 1, 2, 1, 1}, {1, 1, 2, 2, 2},
       {4, 1, 4, 4, 1014}};
  std::vector<std::vector<int>> out =
      {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {110, 0, 0, 0, 114}, {210, 0, 0, 0, 214},
       {310, 0, 0, 113, 314}, {410, 0, 0, 213, 414}, {610, 211, 112, 313, 614}, {710, 311, 412, 613, 714},
       {810, 411, 512, 713, 1014}};
  if (out != Solution::candyCrush(in)) {
    throw std::runtime_error("error");
  }
  return 0;
}
