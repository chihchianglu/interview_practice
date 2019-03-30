//
// Created by Lu, Chih-chiang on 2019-02-05.
//

/**
 * Combination Sum II
 *
 * Given a collection of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static void helper(std::vector<int> &candidates,
                     int target,
                     int start,
                     std::vector<int> &combination,
                     std::vector<std::vector<int>> &res) {
    if (target < 0) {
      return;
    } else if (target == 0) {
      res.push_back(combination);
      return;
    }

    for (int i = start; i < candidates.size(); ++i) {
      if (i > start && candidates[i] == candidates[i - 1]) {
        // input [1, 1, 1, 1, 1, 3] target 6, during backtracing, we could use the same number
        continue;
      }
      combination.push_back(candidates[i]);
      helper(candidates, target - candidates[i], i + 1, combination, res);
      combination.pop_back();
    }
  }
  static std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> combination;
    std::sort(candidates.begin(), candidates.end());
    helper(candidates, target, 0, combination, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> out_1 = {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
  std::vector<int> candidates_1 = {10, 1, 2, 7, 6, 1, 5};
  std::vector<std::vector<int>> out_2 = {{1, 1, 1, 3}};
  std::vector<int> candidates_2 = {1, 1, 1, 1, 1, 3};
  if (Solution::combinationSum2(candidates_1, 8) != out_1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::combinationSum2(candidates_2, 6) != out_2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
