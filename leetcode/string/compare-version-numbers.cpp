//
// Created by Lu, Chih-chiang on 2019-03-22.
//

/**
 * Compare Version Numbers
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level
 * revision of the second first-level revision.
 *
 * Example 1:
 *
 * Input: version1 = "0.1", version2 = "1.1"
 * Output: -1
 * Example 2:
 *
 * Input: version1 = "1.0.1", version2 = "1"
 * Output: 1
 * Example 3:
 *
 * Input: version1 = "7.5.2.4", version2 = "7.5.3"
 * Output: -1
 */

#include <string>
#include <sstream>
#include <stdexcept>

// 由于这道题我们需要将版本号以’.'分开，那么我们可以借用强大的字符串流stringstream的功能来实现分段和转为整数，使用这种方法写的代码很简洁
class Solution {
 public:
  static int compareVersion(std::string version1, std::string version2) {
    std::stringstream v1(version1 + "."), v2(version2 + ".");
    int d1 = 0, d2 = 0;
    char dot = '.';
    while (v1.good() || v2.good()) {
      if (v1.good()) {
        v1 >> d1 >> dot;
      }
      if (v2.good()) {
        v2 >> d2 >> dot;
      }
      if (d1 > d2) {
        return 1;
      } else if (d1 < d2) {
        return -1;
      }
      d1 = d2 = 0;
    }
    return 0;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::compareVersion("0.1", "1.1") != -1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::compareVersion("1.0.1", "1") != 1) {
    throw std::runtime_error("error 2");
  }
  if (Solution::compareVersion("7.5.2.4", "7.5.3") != -1) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
