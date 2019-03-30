//
// Created by Lu, Chih-chiang on 2019-03-16.
//

/**
 * Longest Palindromic Substring
 *
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example:
 *
 * Input: "babad"
 *
 * Output: "bab"
 *
 * Note: "aba" is also a valid answer.
 * Example:
 *
 * Input: "cbbd"
 *
 * Output: "bb"
 *
 */

#include <string>
#include <vector>
#include <stdexcept>

// 此题可以用动态规划Dynamic Programming来解，跟Palindrome Partitioning II 拆分回文串之二的解法很类似，
// 我们维护一个二维数组dp，其中dp[i][j]表示字符串区间[i, j]是否为回文串，
// 当i = j时，只有一个字符，肯定是回文串，如果i = j + 1，说明是相邻字符，此时需要判断s[i]是否等于s[j]，
// 如果i和j不相邻，即i - j >= 2时，除了判断s[i]和s[j]相等之外，dp[j + 1][i - 1]若为真，就是回文串，通过以上分析，可以写出递推式如下：
// dp[i, j] = 1                                 if i == j
//          = s[i] == s[j]                      if j = i + 1
//          = s[i] == s[j] && dp[i + 1][j - 1]  if j > i + 1
class Solution {
 public:
  static std::string longestPalindrome(std::string s) {
    int n = s.size();
    if (n == 0) {
      return std::string();
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::string res;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        dp[i][j] = s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]);
        if (dp[i][j] && j - i + 1 > res.size()) {
          res = s.substr(i, j - i + 1);
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::longestPalindrome("babad") != "aba") {
    throw std::runtime_error("error 1");
  }
  if (Solution::longestPalindrome("cbbd") != "bb") {
    throw std::runtime_error("error 2");
  }
  return 0;
}
