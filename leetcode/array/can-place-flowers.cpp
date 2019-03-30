//
// Created by Lu, Chih-chiang on 2018-12-27.
//

/**
 * Can Place Flowers
 *
 * Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot
 * be planted in adjacent plots - they would compete for water and both would die.
 *
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a
 * number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
 *
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 *
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 *
 * Note:
 * - The input array won't violate no-adjacent-flowers rule.
 * - The input array size is in the range of [1, 20000].
 * - n is a non-negative integer which won't exceed the input array size.
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
    for (int i = 0; i < flowerbed.size() && n > 0; ++i) {
      if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0)
          && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
        flowerbed[i] = 1;
        --n;
      }
    }
    return n <= 0;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> flowerbed = {1, 0, 0, 0, 1};

  if (!Solution::canPlaceFlowers(flowerbed, 1)) {
    throw std::runtime_error("error 1");
  }

  if (Solution::canPlaceFlowers(flowerbed, 2)) {
    throw std::runtime_error("error 2");
  }

  return 0;
}
