//
// Created by Lu, Chih-chiang on 2019-02-01.
//

/**
 * Escape The Ghosts
 *
 * You are playing a simplified Pacman game. You start at the point (0, 0), and your destination is
 * (target[0], target[1]). There are several ghosts on the map, the i-th ghost starts at (ghosts[i][0],
 * ghosts[i][1]).
 *
 * Each turn, you and all ghosts simultaneously *may* move in one of 4 cardinal directions: north, east,
 * west, or south, going from the previous point to a new point 1 unit of distance away.
 *
 * You escape if and only if you can reach the target before any ghost reaches you (for any given moves
 * the ghosts may take.)  If you reach any square (including the target) at the same time as a ghost,
 * it doesn't count as an escape.
 *
 * Return True if and only if it is possible to escape.
 *
 * Example 1:
 *
 * Input:
 * ghosts = [[1, 0], [0, 3]]
 * target = [0, 1]
 *
 * Output: true
 *
 * Explanation:
 * You can directly reach the destination (0, 1) at time 1, while the ghosts located at (1, 0) or (0, 3)
 * have no way to catch up with you.
 *
 * Example 2:
 *
 * Input:
 * ghosts = [[1, 0]]
 * target = [2, 0]
 *
 * Output: false
 *
 * Explanation:
 * You need to reach the destination (2, 0), but the ghost at (1, 0) lies between you and the destination.
 *
 * Example 3:
 *
 * Input:
 * ghosts = [[2, 0]]
 * target = [1, 0]
 *
 * Output: false
 *
 * Explanation:
 * The ghost can reach the target at the same time as you.
 *
 * Note:
 *
 * - All points have coordinates with absolute value <= 10000.
 * - The number of ghosts will not exceed 100.
 */

#include <vector>
#include <stdexcept>

// 这道题就是经典的吃豆人游戏啦，不过是简化版，小人只能躲开鬼魂，并不能吃大力丸，反干鬼魂。小人在原点，
// 有若干个鬼魂在不同的位置，给了一个目标点，问小人能不能安全到达目标点。这里的鬼魂的设定跟游戏中的一样，都是很智能的，会朝着你移动，
// 而且这里设定了如果跟鬼魂同时到达目标点也算输。那么实际上这道题就是要求出小人到目标点的最短距离，
// 注意这里的距离不是两点之间的Euclidean距离，而应该是曼哈顿距离，即横纵坐标分别求差的绝对值再相加。求出小人到目标点到最短距离后，
// 我们还要求每个鬼魂到目标点的最短距离，如果有一个鬼魂到目标带你的最短距离小于等于小人到目标点到最短距的话，那么就返回false，否则返回true
class Solution {
 public:
  static bool escapeGhosts(std::vector<std::vector<int>> &ghosts, std::vector<int> &target) {
    int my_dist = std::abs(target[0]) + std::abs(target[1]);
    for (auto &ghost : ghosts) {
      int g_dis = std::abs(ghost[0] - target[0]) + std::abs(ghost[1] - target[1]);
      if (g_dis <= my_dist) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> g1 = {{1, 0}, {0, 3}};
  std::vector<std::vector<int>> g2 = {{1, 0}};
  std::vector<std::vector<int>> g3 = {{2, 0}};
  std::vector<int> t1 = {0, 1};
  std::vector<int> t2 = {2, 0};
  std::vector<int> t3 = {1, 0};
  if (!Solution::escapeGhosts(g1, t1)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::escapeGhosts(g2, t2)) {
    throw std::runtime_error("error 2");
  }
  if (Solution::escapeGhosts(g3, t3)) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
