//
// Created by Lu, Chih-chiang on 2019-02-05.
//

/**
 * Combinations
 *
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static void helper(int n, int k, int start, std::vector<int> &combination, std::vector<std::vector<int>> &res) {
    if (combination.size() == k) {
      res.push_back(combination);
      return;
    }
    for (int i = start; i <= n; ++i) {
      combination.push_back(i);
      helper(n, k, i + 1, combination, res);
      combination.pop_back();
    }
  }
  static std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> combination;
    helper(n, k, 1, combination, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> out = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
  if (Solution::combine(4, 2) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
