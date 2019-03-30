//
// Created by Lu, Chih-chiang on 2018-12-29.
//

/**
 * First Missing Positive
 *
 * Given an unsorted integer array, find the smallest missing positive integer.
 *
 * Example 1:
 *
 * Input: [1,2,0]
 * Output: 3
 *
 * Example 2:
 *
 * Input: [3,4,-1,1]
 * Output: 2
 *
 * Example 3:
 *
 * Input: [7,8,9,11,12]
 * Output: 1
 *
 * Note:
 *
 * Your algorithm should run in O(n) time and uses constant extra space.
 */

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <unordered_set>

class Solution {
 public:
  static int firstMissingPositive_set(std::vector<int> &nums) {
    int max = 0;
    std::unordered_set<int> cache(nums.size());
    for (auto &num : nums) {
      if (num <= 0) {
        continue;
      } else if (num > max) {
        max = num;
      }
      cache.insert(num);
    }
    for (int i = 1; i <= max; i++) {
      if (cache.find(i) == cache.end()) {
        return i;
      }
    }
    return max + 1;
  }
  //
  // 我们的思路是把1放在数组第一个位置nums[0]，2放在第二个位置nums[1]，即需要把nums[i]放在nums[nums[i] - 1]上，那么我们遍历整个数组，
  // 如果nums[i] != i + 1, 而nums[i]为整数且不大于n，另外nums[i]不等于nums[nums[i] - 1]的话，我们将两者位置调换，如果不满足上述条件直接跳过，
  // 最后我们再遍历一遍数组，如果对应位置上的数不正确则返回正确的数
  //
  static int firstMissingPositive(std::vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return n + 1;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 2, 0};
  std::vector<int> vec2 = {3, 4, -1, 1};
  std::vector<int> vec3 = {7, 8, 9, 11, 12};

  if (Solution::firstMissingPositive_set(vec1) != 3) {
    throw std::runtime_error("error 1");
  }
  if (Solution::firstMissingPositive_set(vec2) != 2) {
    throw std::runtime_error("error 2");
  }
  if (Solution::firstMissingPositive_set(vec3) != 1) {
    throw std::runtime_error("error 3");
  }

  if (Solution::firstMissingPositive(vec1) != 3) {
    throw std::runtime_error("error 4");
  }
  if (Solution::firstMissingPositive(vec2) != 2) {
    throw std::runtime_error("error 5");
  }
  if (Solution::firstMissingPositive(vec3) != 1) {
    throw std::runtime_error("error 6");
  }
  return 0;
}
