//
// Created by Lu, Chih-chiang on 2019-03-23.
//

/**
 * Isomorphic Strings
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No
 * two characters may map to the same character but a character may map to itself.
 *
 * Example 1:
 *
 * Input: s = "egg", t = "add"
 * Output: true
 *
 * Example 2:
 *
 * Input: s = "foo", t = "bar"
 * Output: false
 *
 * Example 3:
 *
 * Input: s = "paper", t = "title"
 * Output: true
 *
 * Note:
 * You may assume both s and t have the same length.
 */

#include <string>
#include <vector>
#include <stdexcept>

// 这道题让我们求同构字符串，就是说原字符串中的每个字符可由另外一个字符替代，可以被其本身替代，相同的字符一定要被同一个字符替代，
// 且一个字符不能被多个字符替代，即不能出现一对多的映射。根据一对一映射的特点，我们需要用两个哈希表分别来记录原字符串和目标字符串中字符出现情况，
// 由于ASCII码只有256个字符，所以我们可以用一个256大小的数组来代替哈希表，并初始化为0，我们遍历原字符串，分别从源字符串和目标字符串取出一个字符，
// 然后分别在两个哈希表中查找其值，若不相等，则返回false，若相等，将其值更新为i + 1，因为默认的值是0，所以我们更新值为i + 1，
// 这样当 i=0 时，则映射为1，如果不加1的话，那么就无法区分是否更新了 aba baa
class Solution {
 public:
  static bool isIsomorphic(std::string s, std::string t) {
    std::vector<int> s_map(256, 0), t_map(256, 0);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s_map[s[i]] != t_map[t[i]]) {
        return false;
      }
      s_map[s[i]] = i + 1;
      t_map[t[i]] = i + 1;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  if (!Solution::isIsomorphic("egg", "add")) {
    throw std::runtime_error("error 1");
  }
  if (Solution::isIsomorphic("foo", "bar")) {
    throw std::runtime_error("error 2");
  }
  if (!Solution::isIsomorphic("paper", "title")) {
    throw std::runtime_error("error 3");
  }
  if (Solution::isIsomorphic("aba", "baa")) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
