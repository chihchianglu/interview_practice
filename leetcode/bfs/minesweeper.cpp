//
// Created by Lu, Chih-chiang on 2019-03-08.
//

/**
 * Minesweeper
 *
 * You are given a 2D char matrix representing the game board.
 * 'M' represents an unrevealed mine,
 * 'E' represents an unrevealed empty square,
 * 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines,
 * digit ('1' to '8') represents how many mines are adjacent to this revealed square,
 * 'X' represents a revealed mine.
 *
 * Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'),
 * return the board after revealing this position according to the following rules:
 *
 * - If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * - If an empty square ('E') with no adjacent mines is revealed,
 *   then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
 * - If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8')
 *   representing the number of adjacent mines.
 *
 * Return the board when no more squares will be revealed.
 *
 * Example 1:
 * Input:
 *
 * [['E', 'E', 'E', 'E', 'E'],
 *  ['E', 'E', 'M', 'E', 'E'],
 *  ['E', 'E', 'E', 'E', 'E'],
 *  ['E', 'E', 'E', 'E', 'E']]
 *
 * Click : [3,0]
 *
 * Output:
 *
 * [['B', '1', 'E', '1', 'B'],
 *  ['B', '1', 'M', '1', 'B'],
 *  ['B', '1', '1', '1', 'B'],
 *  ['B', 'B', 'B', 'B', 'B']]
 *
 * Example 2:
 * Input:
 *
 * [['B', '1', 'E', '1', 'B'],
 *  ['B', '1', 'M', '1', 'B'],
 *  ['B', '1', '1', '1', 'B'],
 *  ['B', 'B', 'B', 'B', 'B']]
 *
 * Click : [1,2]
 *
 * Output:
 *
 * [['B', '1', 'E', '1', 'B'],
 *  ['B', '1', 'X', '1', 'B'],
 *  ['B', '1', '1', '1', 'B'],
 *  ['B', 'B', 'B', 'B', 'B']]
 *
 * Note:
 * - The range of the input matrix's height and width is [1,50].
 * - The click position will only be an unrevealed square ('M' or 'E'),
 *   which also means the input board contains at least one clickable square.
 * - The input board won't be a stage when game is over (some mines have been revealed).
 * - For simplicity, not mentioned rules should be ignored in this problem. For example,
 *   you don't need to reveal all the unrevealed mines when the game is over,
 *   consider any cases that you will win the game or flag any squares.
 */

#include <queue>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>> &board, std::vector<int> &click) {
    int x = click[0], y = click[1], mine_counts = 0;
    if (board[x][y] == 'M') {
      // If a mine ('M') is revealed, then the game is over - change it to 'X'
      board[x][y] = 'X';
    } else {
      // bfs
      std::vector<int> dirs_x = {-1, -1, -1, 0, 0, 1, 1, 1};
      std::vector<int> dirs_y = {-1, 0, 1, -1, 1, -1, 0, 1};
      int rows = board.size(), cols = board[0].size();
      std::queue<std::vector<int>> q{{click}};
      while (!q.empty()) {
        auto pos = q.front();
        q.pop();
        x = pos[0];
        y = pos[1];

        // count the adjacent mines
        mine_counts = 0;
        for (int i = 0; i < 8; ++i) {
          int neighbor_x = x + dirs_x[i], neighbor_y = y + dirs_y[i];
          if (neighbor_x >= 0 && neighbor_x < rows && neighbor_y >= 0 && neighbor_y < cols
              && board[neighbor_x][neighbor_y] == 'M') {
            ++mine_counts;
          }
        }
        if (mine_counts > 0) {
          // If an empty square ('E') with at least one adjacent mine is revealed,
          // then change it to a digit ('1' to '8') representing the number of adjacent mines.
          board[x][y] = char(mine_counts + '0');
        } else {
          // If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B')
          // and all of its adjacent unrevealed squares should be revealed recursively.
          board[x][y] = 'B';

          for (int i = 0; i < 8; ++i) {
            int neighbor_x = x + dirs_x[i], neighbor_y = y + dirs_y[i];
            if (neighbor_x >= 0 && neighbor_x < rows && neighbor_y >= 0 && neighbor_y < cols
                && board[neighbor_x][neighbor_y] == 'E') {
              q.push(std::move(std::vector<int>{neighbor_x, neighbor_y}));
              board[neighbor_x][neighbor_y] = 'B';
            }
          }
        }
      }
    }
    return board;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<char>> in_1 =
      {{'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'M', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}};
  std::vector<int> click_1 = {3, 0};
  std::vector<std::vector<char>> in_2 =
      {{'B', '1', 'E', '1', 'B'}, {'B', '1', 'M', '1', 'B'}, {'B', '1', '1', '1', 'B'}, {'B', 'B', 'B', 'B', 'B'}};
  std::vector<int> click_2 = {1, 2};
  std::vector<std::vector<char>> out_1 =
      {{'B', '1', 'E', '1', 'B'}, {'B', '1', 'M', '1', 'B'}, {'B', '1', '1', '1', 'B'}, {'B', 'B', 'B', 'B', 'B'}};
  std::vector<std::vector<char>> out_2 =
      {{'B', '1', 'E', '1', 'B'}, {'B', '1', 'X', '1', 'B'}, {'B', '1', '1', '1', 'B'}, {'B', 'B', 'B', 'B', 'B'}};
  if (Solution::updateBoard(in_1, click_1) != out_1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::updateBoard(in_2, click_2) != out_2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
