//
// Created by Lu, Chih-chiang on 2019-03-23.
//

/**
 * Valid Word Square
 *
 * Given a sequence of words, check whether it forms a valid word square.
 *
 * A sequence of words forms a valid word square if the kth row and column read the exact same string,
 * where 0 ≤ k < max(numRows, numColumns).
 *
 * Note:
 * 1. The number of words given is at least 1 and does not exceed 500.
 * 2. Word length will be at least 1 and does not exceed 500.
 * 3. Each word contains only lowercase English alphabet a-z.
 *
 * Example 1:
 *
 * Input:
 * [
 *   "abcd",
 *   "bnrt",
 *   "crmy",
 *   "dtye"
 * ]
 *
 * Output:
 * true
 *
 * Explanation:
 * The first row and first column both read "abcd".
 * The second row and second column both read "bnrt".
 * The third row and third column both read "crmy".
 * The fourth row and fourth column both read "dtye".
 *
 * Therefore, it is a valid word square.
 *
 * Example 2:
 *
 * Input:
 * [
 *   "abcd",
 *   "bnrt",
 *   "crm",
 *   "dt"
 * ]
 *
 * Output:
 * true
 *
 * Explanation:
 * The first row and first column both read "abcd".
 * The second row and second column both read "bnrt".
 * The third row and third column both read "crm".
 * The fourth row and fourth column both read "dt".
 *
 * Therefore, it is a valid word square.
 *
 * Example 3:
 *
 * Input:
 * [
 *   "ball",
 *   "area",
 *   "read",
 *   "lady"
 * ]
 *
 * Output:
 * false
 *
 * Explanation:
 * The third row reads "read" while the third column reads "lead".
 *
 * Therefore, it is NOT a valid word square.
 */

#include <string>
#include <vector>
#include <stdexcept>

// 这道题给了我们一个二位数组，每行每列都是一个单词，需要满足第k行的单词和第k列的单词要相等，这里不要求每一个单词的长度都一样，
// 只要对应位置的单词一样即可。那么这里实际上也就是一个遍历二维数组，然后验证对应位上的字符是否相等的问题，由于各行的单词长度不一定相等，
// 所以我们在找对应位置的字符时，要先判断是否越界，即对应位置是否有字符存在，遇到不符合要求的地方直接返回false，全部遍历结束后返回true
class Solution {
 public:
  static bool validWordSquare(std::vector<std::string> &words) {
    if (words.empty()) {
      return true;
    } else if (words.size() != words[0].size()) {
      return false;
    }
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words[i].size(); ++j) {
        if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i]) {
          return false;
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> vec_1{"abcd", "bnrt", "crmy", "dtye"};
  std::vector<std::string> vec_2{"abcd", "bnrt", "crm", "dt"};
  std::vector<std::string> vec_3{"ball", "area", "read", "lady"};
  if (!Solution::validWordSquare(vec_1)) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::validWordSquare(vec_2)) {
    throw std::runtime_error("error 2");
  }
  if (Solution::validWordSquare(vec_3)) {
    throw std::runtime_error("error 3");
  }
  return 0;
}
