//
// Created by Lu, Chih-chiang on 2019-03-16.
//

/**
 * Decode Ways
 *
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given a non-empty string containing only digits, determine the total number of ways to decode it.
 *
 * Example 1:
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 * Example 2:
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */

#include <string>
#include <vector>
#include <stdexcept>

// 解码是有规律的，所以我们可以尝试动态规划。假设数组dp[i]表示从头到字符串的第i位，一共有多少种解码方法的话，
// 那么如果字符串的第i-1位和第i位能组成一个10到26的数字，说明我们是在第i-2位的解码方法上继续解码。
// 如果字符串的第i-1位和第i位不能组成有效二位数字，而且第i位不是0的话，说明我们是在第i-1位的解码方法上继续解码。
// 所以，如果两个条件都符合，则dp[i]=dp[i-1]+dp[i-2]，否则dp[i]=dp[i-1]。
class Solution {
 public:
  static int numDecodings(std::string s) {
    if (s.empty() || s[0] == '0') {
      return 0;
    }
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      // 如果字符串的第i-1位和第i位能组成一个10到26的数字，说明我们可以在第i-2位的解码方法上继续解码
      if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
        dp[i] += dp[i - 2];
      }
      // 如果字符串的第i-1位和第i位不能组成有效二位数字，在第i-1位的解码方法上继续解码
      if (s[i - 1] > '0') {
        dp[i] += dp[i - 1];
      }
    }
    return dp.back();
  }
};

int main(int argc, char *argv[]) {
  if (Solution::numDecodings("12") != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::numDecodings("226") != 3) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
