//
// Created by Lu, Chih-chiang on 2019-03-06.
//

/**
 * Valid Parentheses
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <stack>
#include <string>
#include <stdexcept>

// char +/- char -> integer, ex: 'b' - 'a' -> 1
// integer +/- char -> char, ex: 9 + '0' -> '9'
class Solution {
 public:
  static bool isValid(std::string s) {
    std::stack<char> stk;
    for (char c : s) {
      if (c == '(') {
        stk.push(')');
      } else if (c == '{') {
        stk.push('}');
      } else if (c == '[') {
        stk.push(']');
      } else {
        if (stk.empty()) {
          return false;
        } else {
          auto ch = stk.top();
          stk.pop();
          if (ch != c) {
            return false;
          }
        }
      }
    }
    return stk.empty();
  }
};

int main(int argc, char *argv[]) {
  if (!Solution::isValid("()")) {
    throw std::runtime_error("error 1");
  }
  if (!Solution::isValid("()[]{}")) {
    throw std::runtime_error("error 2");
  }
  if (Solution::isValid("(]")) {
    throw std::runtime_error("error 3");
  }
  if (Solution::isValid("([)]")) {
    throw std::runtime_error("error 4");
  }
  if (!Solution::isValid("{[]}")) {
    throw std::runtime_error("error 5");
  }
  return 0;
}
