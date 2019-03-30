//
// Created by Lu, Chih-chiang on 2019-03-23.
//

/**
 * One Edit Distance
 *
 * Given two strings s and t, determine if they are both one edit distance apart.
 *
 * Note:
 *
 * There are 3 possiblities to satisify one edit distance apart:
 *
 * Insert a character into s to get t
 * Delete a character from s to get t
 * Replace a character of s to get t
 *
 * Example 1:
 *
 * Input: s = "ab", t = "acb"
 * Output: true
 * Explanation: We can insert 'c' into s to get t.
 *
 * Example 2:
 *
 * Input: s = "cab", t = "ad"
 * Output: false
 * Explanation: We cannot get t from s by only one step.
 *
 * Example 3:
 *
 * Input: s = "1203", t = "1213"
 * Output: true
 * Explanation: We can replace '0' with '1' to get t.
 *
 * There're 3 possibilities to satisfy one edit distance apart:
 *
 * 1) Replace 1 char:
 *    s: a B c
 *    t: a D c
 *
 * 2) Delete 1 char from s:
 *    s: a D  b c
 *    t: a    b c
 *
 * 3) Delete 1 char from t
 *    s: a   b c
 *    t: a D b c
 */

#include <string>
#include <stdexcept>

// 这道题是之前那道Edit Distance的拓展，然而这道题并没有那道题难，这道题只让我们判断两个字符串的编辑距离是否为1，那么我们只需分下列三种情况来考虑就行了：
// 1. 两个字符串的长度之差大于1，那么直接返回False
// 2. 两个字符串的长度之差等于1，那么长的那个字符串去掉一个字符，剩下的应该和短的字符串相同
// 3. 两个字符串的长度之差等于0，那么两个字符串对应位置的字符只能有一处不同。
// 分析清楚了所有的情况，代码就很好写了

// 我们实际上可以让代码写的更加简洁，只需要对比两个字符串对应位置上的字符，如果遇到不同的时候，这时我们看两个字符串的长度关系，
// 如果相等，那么我们比较当前位置后的字串是否相同，如果s的长度大，那么我们比较s的下一个位置开始的子串，和t的当前位置开始的子串是否相同，
// 反之如果t的长度大，那么我们比较t的下一个位置开始的子串，和s的当前位置开始的子串是否相同。如果循环结束，都没有找到不同的字符，
// 那么此时我们看两个字符串的长度是否相差1
class Solution {
 public:
  static bool isOneEditDistance(std::string s, std::string t) {
    int lower_bound = std::min(s.size(), t.size());
    for (int i = 0; i < lower_bound; ++i) {
      if (s[i] != t[i]) {
        if (s.size() == t.size()) {
          return s.substr(i + 1) == t.substr(i + 1);
        } else if (s.size() < t.size()) {
          return s.substr(i) == t.substr(i + 1);
        } else {
          return s.substr(i + 1) == t.substr(i);
        }
      }
    }
    return std::abs((int) s.size() - (int) t.size()) == 1;
  }
};

int main(int argc, char *argv[]) {
  if (!Solution::isOneEditDistance("ab", "acb")) {
    throw std::runtime_error("error 1");
  }
  if (Solution::isOneEditDistance("cab", "ad")) {
    throw std::runtime_error("error 2");
  }
  if (!Solution::isOneEditDistance("1203", "1213")) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
