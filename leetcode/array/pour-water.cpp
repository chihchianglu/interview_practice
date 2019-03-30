//
// Created by Lu, Chih-chiang on 2019-01-04.
//

/**
 * Pour Water
 *
 * We are given an elevation map, heights[i] representing the height of the terrain at that index. The width at each index is 1.
 * After V units of water fall at index K, how much water is at each index?
 * Water first drops at index K and rests on top of the highest terrain or water at that index.
 *
 * Then, it flows according to the following rules:
 * If the droplet would eventually fall by moving left, then move left.
 * Otherwise, if the droplet would eventually fall by moving right, then move right.
 * Otherwise, rise at it's current position.
 *
 * Here, "eventually fall" means that the droplet will eventually be at a lower level if it moves in that direction.
 * Also, "level" means the height of the terrain plus any water in that column.
 * We can assume there's infinitely high terrain on the two sides out of bounds of the array.
 * Also, there could not be partial water being spread out evenly on more than 1 grid block - each unit of water has to be in exactly one block.
 *
 * For example:
 *
 * heights = [5, 4, 2, 1, 2, 3, 2, 1, 0, 1, 2, 4]
 * location = 5
 * water = 13
 *
 * Your output should be: [ 0, 0, 1, 2, 1, 0, 1, 2, 3, 2, 1, 0 ]
 *
 * This is how the container looks like
 *
 *          | water
 *          |
 *          v
 *     +
 *     ++         +
 *     ++WWW+WWWWW+
 *     +++W+++WWW++
 *     ++++++++W+++
 *     ++++++++++++
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> pourWater(std::vector<int> &heights, int V, int K) {
    int n = heights.size();
    std::vector<int> res(n, 0);
    for (int i = 0; i < V; ++i) {
      int l = K, r = K;
      while (l > 0 && heights[l] + res[l] >= heights[l - 1] + res[l - 1]) {
        --l;
      }
      while (l < K && heights[l] + res[l] == heights[l + 1] + res[l + 1]) {
        ++l;
      }
      while (r < n - 1 && heights[r] + res[r] >= heights[r + 1] + res[r + 1]) {
        ++r;
      }
      while (r > K && heights[r] + res[r] == heights[r - 1] + res[r - 1]) {
        --r;
      }
      heights[l] + res[l] < heights[K] + res[K] ? ++res[l] : ++res[r];
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {2, 1, 1, 2, 1, 2, 2};
  std::vector<int> out1 = {0, 1, 1, 1, 1, 0, 0};
  std::vector<int> vec2 = {1, 2, 3, 4};
  std::vector<int> out2 = {1, 1, 0, 0};
  std::vector<int> vec3 = {3, 1, 3};
  std::vector<int> out3 = {1, 3, 1};
  std::vector<int> vec4 = {5, 4, 2, 1, 2, 3, 2, 1, 0, 1, 2, 4};
  std::vector<int> out4 = {0, 0, 1, 2, 1, 0, 1, 2, 3, 2, 1, 0};

  if (Solution::pourWater(vec1, 4, 3) != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::pourWater(vec2, 2, 2) != out2) {
    throw std::runtime_error("error 2");
  }
  if (Solution::pourWater(vec3, 5, 1) != out3) {
    throw std::runtime_error("error 3");
  }
  if (Solution::pourWater(vec4, 13, 5) != out4) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
