//
// Created by Lu, Chih-chiang on 2019-03-06.
//

/**
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 */

#include <stack>
#include <string>
#include <stdexcept>

// char +/- char -> integer, ex: 'b' - 'a' -> 1
// integer +/- char -> char, ex: 9 + '0' -> '9'

// 这道求最长有效括号比之前那道 Valid Parentheses 难度要大一些，这里我们还是借助栈来求解，
// 需要定义个start变量来记录合法括号串的起始位置，我们遍历字符串，如果遇到左括号，则将当前下标压入栈，如果遇到右括号，
// 如果当前栈为空，则将下一个坐标位置记录到start，如果栈不为空，则将栈顶元素取出，此时若栈为空，则更新结果和i - start + 1中的较大值，
// 否则更新结果和i - 栈顶元素中的较大值
class Solution {
 public:
  static int longestValidParentheses(std::string s) {
    int res = 0, start = 0, n = s.size();
    std::stack<int> stk;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else if (s[i] == ')') {
        if (stk.empty()) {
          start = i + 1;
        } else {
          stk.pop();
          res = stk.empty() ? std::max(res, i - start + 1) : std::max(res, i - stk.top());
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::longestValidParentheses("(()") != 2) {
    throw std::runtime_error("error 1");
  }
  if (Solution::longestValidParentheses(")()())") != 4) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
