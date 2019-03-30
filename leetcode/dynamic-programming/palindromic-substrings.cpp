//
// Created by Lu, Chih-chiang on 2019-03-16.
//

/**
 * Palindromic Substrings
 *
 * Given a string, your task is to count how many palindromic substrings in this string.
 *
 * The substrings with different start indexes or end indexes are counted as different
 * substrings even they consist of same characters.
 *
 * Example 1:
 *
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 * Example 2:
 *
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 * Note:
 * The input string length won't exceed 1000.
 */

#include <string>
#include <vector>
#include <stdexcept>

// 我们直接就将dp[i][j]定义成子字符串[i, j]是否是回文串就行了，然后我们i从n-1往0遍历，j从i往n-1遍历，然后我们看s[i]和s[j]是否相等，
// 这时候我们需要留意一下，有了s[i]和s[j]相等这个条件后，i和j的位置关系很重要，如果i和j相等了，那么dp[i][j]肯定是true；
// 如果i和j是相邻的，那么dp[i][j]也是true；如果i和j中间只有一个字符，那么dp[i][j]还是true；如果中间有多余一个字符存在，
// 那么我们需要看dp[i+1][j-1]是否为true，若为true，那么dp[i][j]就是true。赋值dp[i][j]后，如果其为true，结果res自增1
class Solution {
 public:
  static int countSubstrings(std::string s) {
    int n = s.size(), res = 0;
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
        if (dp[i][j]) {
          ++res;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::countSubstrings("abc") != 3) {
    throw std::runtime_error("error 1");
  }
  if (Solution::countSubstrings("aaa") != 6) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
