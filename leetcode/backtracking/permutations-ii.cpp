//
// Created by Lu, Chih-chiang on 2019-03-07.
//

/**
 * Permutations II
 *
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 */

#include <vector>
#include <stdexcept>

class Solution {
 public:
  static void permuteUniqueDFS(std::vector<int> &nums,
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
      } else if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) {
        // 1(i=0) 1(i=1) 2(i=2) 2(i=3) -> 1 1 -> 1 1 2(3) skipped
        continue;
      } else {
        visited[i] = 1;
        out.push_back(nums[i]);
        permuteUniqueDFS(nums, level + 1, visited, out, res);
        out.pop_back();
        visited[i] = 0;
      }
    }
  }
  static std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> out, visited(nums.size(), 0);
    std::sort(nums.begin(), nums.end());
    permuteUniqueDFS(nums, 0, visited, out, res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {1, 1, 2};
  std::vector<std::vector<int>> out = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
  if (Solution::permuteUnique(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
