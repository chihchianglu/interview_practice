//
// Created by Lu, Chih-chiang on 2019-03-09.
//

/**
 * Search Insert Position
 *
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Example 1:
 *
 * Input: [1,3,5,6], 5
 * Output: 2
 *
 * Example 2:
 *
 * Input: [1,3,5,6], 2
 * Output: 1
 *
 * Example 3:
 *
 * Input: [1,3,5,6], 7
 * Output: 4
 *
 * Example 4:
 *
 * Input: [1,3,5,6], 0
 * Output: 0
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int searchInsert(std::vector<int> &nums, int target) {
    if (nums.back() < target) {
      return nums.size();
    }
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        l = mid + 1; // plus 1 is fine because insertion will be on the plus 1 position
      } else {
        r = mid; // don't minus 1, or we could fail for insertion case
      }
    }
    return r;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 3, 5, 6};
  if (Solution::searchInsert(vec, 5) != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::searchInsert(vec, 2) != 1) {
    throw std::runtime_error("error 2");
  }
  if (Solution::searchInsert(vec, 7) != 4) {
    throw std::runtime_error("error 3");
  }
  if (Solution::searchInsert(vec, 0) != 0) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
