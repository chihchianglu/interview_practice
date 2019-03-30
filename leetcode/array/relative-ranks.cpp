//
// Created by Lu, Chih-chiang on 2019-01-04.
//

/**
 * Relative Ranks
 *
 * Given scores of N athletes, find their relative ranks and the people with the top three highest scores,
 * who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
 *
 * Example 1:
 *
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 *
 * Explanation: The first three athletes got the top three highest scores,
 * so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
 *
 * For the left two athletes, you just need to output their relative ranks according to their scores.
 *
 * Note:
 *
 * - N is a positive integer and won't exceed 10,000.
 * - All the scores of athletes are guaranteed to be unique.
 */

#include <map>
#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<std::string> findRelativeRanks(std::vector<int> &nums) {
    int n = nums.size(), idx = 1;
    std::vector<std::string> res(n, "");
    std::map<int, int> map;
    for (int i = 0; i < n; ++i) {
      map[nums[i]] = i;
    }
    for (auto it = map.rbegin(); it != map.rend(); ++it) {
      if (idx == 1) {
        res[it->second] = "Gold Medal";
      } else if (idx == 2) {
        res[it->second] = "Silver Medal";
      } else if (idx == 3) {
        res[it->second] = "Bronze Medal";
      } else {
        res[it->second] = std::to_string(idx);
      }
      ++idx;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> vec = {5, 4, 3, 2, 1};
  std::vector<std::string> out = {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
  if (Solution::findRelativeRanks(vec) != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
