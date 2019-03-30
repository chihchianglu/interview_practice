//
// Created by Lu, Chih-chiang on 2019-01-05.
//

/**
 * Sort Colors
 *
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects
 * of the same color are adjacent, with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this problem.
 *
 * Example:
 *
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *
 * Follow up:
 *
 * - A rather straight forward solution is a two-pass algorithm using counting sort.
 * - First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total
 *   number of 0's, then 1's and followed by 2's.
 * - Could you come up with a one-pass algorithm using only constant space?
 */

#include <vector>
#include <stdexcept>
#include <unordered_map>

class Solution {
 public:
  static void sortColors_v1(std::vector<int> &nums) {
    std::unordered_map<int, int> map;
    int idx = 0, n = nums.size();

    for (int i = 0; i < n; ++i) {
      ++map[nums[i]];
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < map[i]; ++j) {
        nums[idx++] = i;
      }
    }
  }
  static void sortColors(std::vector<int> &nums) {
    int n = nums.size(), red = 0, blue = n - 1;

    for (int i = 0; i <= blue; ++i) {
      if (nums[i] == 0) {
        std::swap(nums[i], nums[red++]);
      } else if (nums[i] == 2) {
        std::swap(nums[i--], nums[blue--]);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {2, 0, 2, 1, 1, 0};
  std::vector<int> vec2 = {2, 0, 2, 1, 1, 0};
  std::vector<int> out = {0, 0, 1, 1, 2, 2};

  Solution::sortColors_v1(vec1);
  if (vec1 != out) {
    throw std::runtime_error("error 1");
  }
  Solution::sortColors(vec2);
  if (vec2 != out) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
