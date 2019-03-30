//
// Created by Lu, Chih-chiang on 2019-03-23.
//

/**
 * Valid Word Abbreviation
 *
 * Given a non-empty string s and an abbreviation abbr,
 * return whether the string matches with the given abbreviation.
 *
 * A string such as "word" contains only the following valid abbreviations:
 *
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 * Notice that only the above abbreviations are valid abbreviations of the string "word".
 * Any other string is not a valid abbreviation of "word".
 *
 * Note:
 * Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.
 *
 * Example 1:
 * Given s = "internationalization", abbr = "i12iz4n":
 *
 * Return true.
 * Example 2:
 * Given s = "apple", abbr = "a2e":
 *
 * Return false.
 */

#include <string>
#include <stdexcept>

// 这道题让我们验证单词缩写，关于单词缩写LeetCode上还有两道相类似的题目Unique Word Abbreviation和Generalized Abbreviation。
// 这道题给了我们一个单词和一个缩写形式，让我们验证这个缩写形式是否是正确的，由于题目中限定了单词中只有小写字母和数字，
// 所以我们只要对这两种情况分别处理即可。我们使用双指针分别指向两个单词的开头，循环的条件是两个指针都没有到各自的末尾，
// 如果指向缩写单词的指针指的是一个数字的话，如果当前数字是0，返回false，因为数字不能以0开头，然后我们要把该数字整体取出来，
// 所以我们用一个while循环将数字整体取出来，然后指向原单词的指针也要对应的向后移动这么多位数。如果指向缩写单词的指针指的是一个字母的话，
// 那么我们只要比两个指针指向的字母是否相同，不同则返回false，相同则两个指针均向后移动一位
class Solution {
 public:
  static bool validWordAbbreviation(std::string word, std::string abbr) {
    int i = 0, j = 0, m = word.size(), n = abbr.size();
    while (i < m && j < n) {
      if (abbr[j] >= '0' && abbr[j] <= '9') {
        if (abbr[j] == '0') {
          return false;
        }
        int val = 0;
        while (j < n && abbr[j] >= '0' && abbr[j] <= '9') {
          val = val * 10 + (abbr[j++] - '0');
        }
        i += val;
      } else {
        if (word[i++] != abbr[j++]) {
          return false;
        }
      }
    }
    return i == m && j == n;
  }
};

int main(int argc, char *argv[]) {
  if (!Solution::validWordAbbreviation("internationalization", "i12iz4n")) {
    throw std::runtime_error("error 1");
  }
  if (Solution::validWordAbbreviation("apple", "a2e")) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
