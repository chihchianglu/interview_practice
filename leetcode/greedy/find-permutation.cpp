//
// Created by Lu, Chih-chiang on 2019-01-31.
//

/**
 * Find Permutation
 *
 * By now, you are given a secret signature consisting of character 'D' and 'I'.
 * 'D' represents a decreasing relationship between two numbers,
 * 'I' represents an increasing relationship between two numbers.
 * And our secret signature was constructed by a special integer array,
 * which contains uniquely all the different number from 1 to n (n is the length of the secret signature plus 1).
 * For example, the secret signature "DI" can be constructed by array [2,1,3] or [3,1,2],
 * but won't be constructed by array [3,2,4] or [2,1,3,4], which are both illegal constructing special string that
 * can't represent the "DI" secret signature.
 *
 * On the other hand, now your job is to find the lexicographically smallest permutation of [1, 2, ... n]
 * could refer to the given secret signature in the input.
 *
 * Example 1:
 *
 * Input: "I"
 * Output: [1,2]
 *
 * Explanation: [1,2] is the only legal initial spectial string can construct secret signature "I",
 * where the number 1 and 2 construct an increasing relationship.
 *
 * Example 2:
 *
 * Input: "DI"
 * Output: [2,1,3]
 *
 * Explanation: Both [2,1,3] and [3,1,2] can construct the secret signature "DI",
 * but since we want to find the one with the smallest lexicographical permutation, you need to output [2,1,3]
 *
 * Note:
 *
 * - The input string will only contain the character 'D' and 'I'.
 * - The length of input string is a positive integer and will not exceed 10,000
 */

#include <stack>
#include <string>
#include <vector>
#include <stdexcept>

// push numbers into stack, and pop out when run into 'I'
class Solution {
 public:
  static std::vector<int> findPermutation(std::string s) {
    int n = s.size(), count = 0;
    std::vector<int> res(n + 1);
    std::stack<int> st;
    // ex: D D I I D I
    for (int i = 0; i < n; ++i) {
      st.push(i + 1);

      if (s[i] == 'I') {
        while (!st.empty()) {
          res[count++] = st.top();
          st.pop();
        }
      }
    }
    st.push(s.size() + 1);
    while (!st.empty()) {
      res[count++] = st.top();
      st.pop();
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  std::string s1 = "I";
  std::string s2 = "DI";
  std::string s3 = "DDIIDI";
  std::string s4 = "DDIIDD";
  std::vector<int> out1 = {1, 2};
  std::vector<int> out2 = {2, 1, 3};
  std::vector<int> out3 = {3, 2, 1, 4, 6, 5, 7};
  std::vector<int> out4 = {3, 2, 1, 4, 7, 6, 5};
  if (Solution::findPermutation(s1) != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::findPermutation(s2) != out2) {
    throw std::runtime_error("error 2");
  }
  if (Solution::findPermutation(s3) != out3) {
    throw std::runtime_error("error 3");
  }
  if (Solution::findPermutation(s4) != out4) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
