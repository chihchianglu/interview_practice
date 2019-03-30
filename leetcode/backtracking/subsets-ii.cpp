//
// Created by Lu, Chih-chiang on 2019-03-07.
//

/**
 * Subsets II
 *
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * For example,
 * If nums = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
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
      if (i > start && nums[i] == nums[i - 1]) {
        // 1(i=0) 2(i=1) 2(i=2) -> 1 -> 1 2(i=2) skipped
        continue;
      }
      out.push_back(nums[i]);
      backtracking(nums, i + 1, out, res);
      out.pop_back();
    }
  }
  static std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> out;
    std::sort(nums.begin(), nums.end());
    backtracking(nums, 0, out, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {2, 1, 2};
  std::vector<std::vector<int>> out = {{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
  if (Solution::subsetsWithDup(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
