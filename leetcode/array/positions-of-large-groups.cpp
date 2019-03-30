//
// Created by Lu, Chih-chiang on 2019-01-03.
//

/**
 * Positions of Large Groups
 *
 * In a string S of lowercase letters, these letters form consecutive groups of the same character.
 *
 * For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
 *
 * Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
 *
 * The final answer should be in lexicographic order.
 *
 * Example 1:
 *
 * Input: "abbxxxxzzy"
 * Output: [[3,6]]
 * Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
 *
 * Example 2:
 *
 * Input: "abc"
 * Output: []
 * Explanation: We have "a","b" and "c" but no large group.
 *
 * Example 3:
 *
 * Input: "abcdddeeeeaabbbcd"
 * Output: [[3,5],[6,9],[12,14]]
 *
 * Note:  1 <= S.length <= 1000
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<std::vector<int>> largeGroupPositions(std::string S) {
    std::vector<std::vector<int>> res;
    int n = S.size(), i = 0, j = 0;
    while (j < n) {
      while (j < n && S[i] == S[j]) {
        ++j;
      }
      if (j - i >= 3) {
        res.push_back(std::vector<int>{i, j - 1});
      }
      i = j;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::string s1 = "abbxxxxzzy";
  std::string s2 = "abc";
  std::string s3 = "abcdddeeeeaabbbcd";
  std::string s4 = "aaa";
  std::vector<std::vector<int>> out1 = {{3, 6}};
  std::vector<std::vector<int>> out2 = {};
  std::vector<std::vector<int>> out3 = {{3, 5}, {6, 9}, {12, 14}};
  std::vector<std::vector<int>> out4 = {{0, 2}};

  if (Solution::largeGroupPositions(s1) != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::largeGroupPositions(s2) != out2) {
    throw std::runtime_error("error 2");
  }
  if (Solution::largeGroupPositions(s3) != out3) {
    throw std::runtime_error("error 3");
  }
  if (Solution::largeGroupPositions(s4) != out4) {
    throw std::runtime_error("error 4");
  }

  return 0;
}
