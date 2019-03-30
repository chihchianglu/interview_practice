//
// Created by Lu, Chih-chiang on 2019-03-11.
//

/**
 * Decode String
 *
 * Given an encoded string, return it's decoded string.
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets
 * is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 *
 * You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any digits and that digits are only for those
 * repeat numbers, k. For example, there won't be input like 3a or 2[4].
 *
 * Examples:
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */

#include <string>
#include <stdexcept>

class Solution {
 public:
  static std::string helper(std::string s, int &i) {
    std::string res;
    int n = s.size();
    while (i < n && s[i] != ']') {
      if (s[i] < '0' || s[i] > '9') {
        res += s[i++];
      } else {
        int count = 0;
        while (s[i] >= '0' && s[i] <= '9') {
          count = count * 10 + (s[i++] - '0');
        }
        ++i; // '['
        std::string t = helper(s, i);
        ++i; // ']'
        while (count-- > 0) {
          res += t;
        }
      }
    }
    return res;
  }
  static std::string decodeString(std::string s) {
    int i = 0;
    return helper(s, i);
  }
};

int main(int argc, char *argv[]) {
  if (Solution::decodeString("3[a]2[bc]") != "aaabcbc") {
    throw std::runtime_error("error 1");
  }
  if (Solution::decodeString("3[a2[c]]") != "accaccacc") {
    throw std::runtime_error("error 2");
  }
  if (Solution::decodeString("2[abc]3[cd]ef") != "abcabccdcdcdef") {
    throw std::runtime_error("error 3");
  }
  return 0;
}
