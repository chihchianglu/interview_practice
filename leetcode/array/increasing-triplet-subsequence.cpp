//
// Created by Lu, Chih-chiang on 2018-12-30.
//

/**
 * Increasing Triplet Subsequence
 *
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
 *
 * Formally the function should:
 *
 * Return true if there exists i, j, k
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 * Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
 *
 * Example 1:
 *
 * Input: [1,2,3,4,5]
 * Output: true
 *
 * Example 2:
 *
 * Input: [5,4,3,2,1]
 * Output: false
 */

#include <limits>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static bool increasingTriplet(std::vector<int> &nums) {
    int m1 = std::numeric_limits<int>::max(), m2 = std::numeric_limits<int>::max();
    for (auto &num : nums) {
      if (m1 >= num) {
        m1 = num;
      } else if (m2 >= num) {
        m2 = num;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {5, 4, 3, 2, 1};
  if (!Solution::increasingTriplet(vec1)) {
    throw std::runtime_error("error 1");
  }
  if (Solution::increasingTriplet(vec2)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
