//
// Created by Lu, Chih-chiang on 2019-02-05.
//

/**
 * Combination Sum
 *
 * Given a set of candidate numbers (C) (without duplicates) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [2, 3, 6, 7] and target 7,
 * A solution set is:
 * [
 *   [7],
 *   [2, 2, 3]
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
      combination.push_back(candidates[i]);
      helper(candidates, target - candidates[i], i, combination, res);
      combination.pop_back();
    }
  }
  static std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> combination;
    helper(candidates, target, 0, combination, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> out = {{2, 2, 3}, {7}};
  std::vector<int> candidates = {2, 3, 6, 7};
  if (Solution::combinationSum(candidates, 7) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
