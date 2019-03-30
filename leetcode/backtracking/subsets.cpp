//
// Created by Lu, Chih-chiang on 2019-03-07.
//

/**
 * Subsets
 *
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * For example,
 * If nums = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static void backtracking(std::vector<int> &nums,
                           int start,
                           std::vector<int> &out,
                           std::vector<std::vector<int>> &res) {
    res.push_back(out);
    int n = nums.size();
    for (int i = start; i < n; ++i) {
      out.push_back(nums[i]);
      backtracking(nums, i + 1, out, res);
      out.pop_back();
    }
  }
  static std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> out;
    backtracking(nums, 0, out, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 2, 3};
  std::vector<std::vector<int>> out = {{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}};
  if (Solution::subsets(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
