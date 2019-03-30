//
// Created by Lu, Chih-chiang on 2019-01-14.
//

/**
 * Random Pick Index
 *
 * Given an array of integers with possible duplicates, randomly output the index of a given target number.
 * You can assume that the given target number must exist in the array.
 *
 * Note:
 * The array size can be very large. Solution that uses too much extra space will not pass the judge.
 *
 * Example:
 *
 * int[] nums = new int[] {1,2,3,3,3};
 * Solution solution = new Solution(nums);
 *
 * // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
 * solution.pick(3);
 *
 * // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
 * solution.pick(1);
 *
 * Your Solution object will be instantiated and called as such:
 * var obj = Object.create(Solution).createNew(nums)
 * var param_1 = obj.pick(target)
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  Solution(std::vector<int> nums) : nums_(nums) {}

  int pick(int target) {
    int count = 0, res = -1;
    for (int i = 0; i < nums_.size(); ++i) {
      if (nums_[i] != target) {
        continue;
      }
      ++count;
      if (std::rand() % count == 0) {
        res = i;
      }
    }
    return res;
  }
 private:
  std::vector<int> nums_;
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 2, 3, 3, 3};
  auto obj = new Solution(vec);
  int out1 = obj->pick(3);
  if (out1 != 2 && out1 != 3 && out1 != 4) {
    throw std::runtime_error("error 1");
  }
  if (obj->pick(1)) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
