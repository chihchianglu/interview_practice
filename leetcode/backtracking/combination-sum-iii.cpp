//
// Created by Lu, Chih-chiang on 2019-02-05.
//

/**
 * Combination Sum III
 *
 * Find all possible combinations of k numbers that add up to a number n,
 * given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 *
 * Example 1:
 *
 * Input: k = 3, n = 7
 *
 * Output:
 *
 * [[1,2,4]]
 *
 * Example 2:
 *
 * Input: k = 3, n = 9
 *
 * Output:
 *
 * [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static void helper(int k, int n, int start, std::vector<int> &combination, std::vector<std::vector<int>> &res) {
    if (k < 0 || n < 0) {
      return;
    } else if (k == 0 && n == 0) {
      res.push_back(combination);
      return;
    }

    for (int i = start; i <= 9; ++i) {
      combination.push_back(i);
      helper(k - 1, n - i, i + 1, combination, res);
      combination.pop_back();
    }
  }
  static std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> res;
    std::vector<int> combination;
    helper(k, n, 1, combination, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> out1 = {{1, 2, 4}};
  std::vector<std::vector<int>> out2 = {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
  if (Solution::combinationSum3(3, 7) != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::combinationSum3(3, 9) != out2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
