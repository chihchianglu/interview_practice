//
// Created by Lu, Chih-chiang on 2019-03-07.
//

/**
 * Permutations
 *
 * Given a collection of distinct numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static void permuteDFS(std::vector<int> &nums,
                         int level,
                         std::vector<int> &visited,
                         std::vector<int> &out,
                         std::vector<std::vector<int>> &res) {
    if (level >= nums.size()) {
      res.push_back(out);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (visited[i] == 1) {
        continue;
      }
      visited[i] = 1;
      out.push_back(nums[i]);
      permuteDFS(nums, level + 1, visited, out, res);
      out.pop_back();
      visited[i] = 0;
    }
  }
  static std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> out, visited(nums.size(), 0);
    permuteDFS(nums, 0, visited, out, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 2, 3};
  std::vector<std::vector<int>> out = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  if (Solution::permute(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
