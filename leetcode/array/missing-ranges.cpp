//
// Created by Lu, Chih-chiang on 2019-01-02.
//

/**
 * Missing Ranges
 *
 * Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper],
 * return its missing ranges.
 *
 * Example:
 *
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::string getRange(int l, int r) {
    return (l == r) ? std::to_string(l) : std::to_string(l) + "->" + std::to_string(r);
  }

  static std::vector<std::string> findMissingRanges(std::vector<int> &nums, int lower, int upper) {
    std::vector<std::string> res;
    int next = lower, n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] < next) {
        continue;
      } else if (nums[i] == next) {
        next++;
        continue;
      } else {
        res.push_back(getRange(next, nums[i] - 1));
        next = nums[i] + 1;
      }
    }

    if (next <= upper) {
      res.push_back(getRange(next, upper));
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {0, 1, 3, 50, 75};
  std::vector<std::string> out = {"2", "4->49", "51->74", "76->99"};

  if (Solution::findMissingRanges(vec, 0, 99) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
