//
// Created by Lu, Chih-chiang on 2019-03-14.
//

/**
 * Word Break
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Note:
 *
 * - The same word in the dictionary may be reused multiple times in the segmentation.
 * - You may assume the dictionary does not contain duplicate words.
 *
 * Example 1:
 *
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 *
 * Example 2:
 *
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 *              Note that you are allowed to reuse a dictionary word.
 *
 * Example 3:
 *
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 */

#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_set>

class Solution {
 public:
  static bool wordBreakRecursion(std::string s, std::unordered_set<std::string> &wordDict) {
    if (s.empty()) {
      return true;
    }

    for (int i = 1; i <= s.size(); ++i) {
      std::string prefix = s.substr(0, i);
      std::string rest = s.substr(i);
      if (wordDict.count(prefix) && wordBreakRecursion(rest, wordDict)) {
        return true;
      }
    }
    return false;
  }
  static bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
    return wordBreakRecursion(s, dict);
  }

  // 这道题其实还是一道经典的DP题目，也就是动态规划Dynamic Programming。
  // 博主曾经说玩子数组或者子字符串且求极值的题，基本就是DP没差了，虽然这道题没有求极值，但是玩子字符串也符合DP的状态转移的特点。
  // DP解法的两大难点，定义dp数组跟找出状态转移方程，先来看dp数组的定义，
  // 这里我们就用一个一维的dp数组，其中dp[i]表示范围[0, i)内的子串是否可以拆分，注意这里dp数组的长度比s串的长度大1，
  // 是因为我们要handle空串的情况，我们初始化dp[0]为true，然后开始遍历。
  // 注意这里我们需要两个for循环来遍历，因为此时已经没有递归函数了，所以我们必须要遍历所有的子串，
  // 我们用j把[0, i)范围内的子串分为了两部分，[0, j) 和 [j, i)，其中范围 [0, j) 就是dp[j]，范围 [j, i) 就是s.substr(j, i-j)，
  // 其中dp[j]是之前的状态，我们已经算出来了，可以直接取，只需要在字典中查找s.substr(j, i-j)是否存在了，
  // 如果二者均为true，将dp[i]赋为true，并且break掉，此时就不需要再用j去分[0, i)范围了，因为[0, i)范围已经可以拆分了。
  // 最终我们返回dp数组的最后一个值，就是整个数组是否可以拆分的布尔值了
  static bool wordBreak_dp(std::string s, std::vector<std::string> &wordDict) {
    std::unordered_set<std::string> word_set(wordDict.begin(), wordDict.end());
    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 0; i < dp.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && word_set.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp.back();
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> vec_1 = {"leet", "code"};
  std::vector<std::string> vec_2 = {"apple", "pen"};
  std::vector<std::string> vec_3 = {"cats", "dog", "sand", "and", "cat"};
  if (!Solution::wordBreak_dp("leetcode", vec_1)) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::wordBreak_dp("applepenapple", vec_2)) {
    throw std::runtime_error("error 2");
  }
  if (Solution::wordBreak_dp("catsandog", vec_3)) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
