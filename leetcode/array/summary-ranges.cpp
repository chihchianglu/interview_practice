//
// Created by Lu, Chih-chiang on 2019-01-06.
//

/**
 * Summary Ranges
 *
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * Example 1:
 * Input: [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 *
 * Example 2:
 * Input: [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::string getRange(int l, int r) {
    return (l == r) ? std::to_string(l) : std::to_string(l) + "->" + std::to_string(r);
  }

  static std::vector<std::string> summaryRanges(std::vector<int> &nums) {
    int n = nums.size(), left = 0;
    std::vector<std::string> res;
    for (int i = 1; i <= n; ++i) {
      if (i == n || int(nums[i]) - nums[i - 1] > 1) {
        res.push_back(getRange(nums[left], nums[i - 1]));
        left = i;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec1 = {0, 1, 2, 4, 5, 7};
  std::vector<int> vec2 = {0, 2, 3, 4, 6, 8, 9};
  std::vector<std::string> out1 = {"0->2", "4->5", "7"};
  std::vector<std::string> out2 = {"0", "2->4", "6", "8->9"};
  if (Solution::summaryRanges(vec1) != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::summaryRanges(vec2) != out2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
