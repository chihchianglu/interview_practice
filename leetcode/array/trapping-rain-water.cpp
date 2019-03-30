//
// Created by Lu, Chih-chiang on 2018-12-20.
//

/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped.
 * Thanks Marcos for contributing this image!
 */

#include <cmath>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int trap(std::vector<int> &height) {
    if (height.empty()) {
      return 0;
    }
    int max = 0, res = 0;
    std::vector<int> container(height);
    for (int i = 0; i < height.size(); i++) {
      container[i] = max;
      max = std::max(max, height[i]);
    }
    max = 0;
    for (int i = height.size() - 1; i >= 0; i--) {
      container[i] = std::min(max, container[i]);
      max = std::max(max, height[i]);
      int num = container[i] - height[i];
      res += num > 0 ? num : 0;
    }
    return res;
  }

  // focus on this solution
  static int trap2(std::vector<int> &height) {
    if (height.empty()) {
      return 0;
    }

    int l = 0, r = height.size() - 1, res = 0;
    while (l < r) {
      int min = std::min(height[l], height[r]);
      if (height[l] == min) {
        l++;
        while (l < r && height[l] < min) {
          res += min - height[l];
          l++;
        }
      } else {
        r--;
        while (l < r && height[r] < min) {
          res += min - height[r];
          r--;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  if (Solution::trap(vec) != 6) {
    throw std::runtime_error("error 1");
  }
  if (Solution::trap2(vec) != 6) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
