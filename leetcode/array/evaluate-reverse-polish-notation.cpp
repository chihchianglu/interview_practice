//
// Created by Lu, Chih-chiang on 2018-12-28.
//

/**
 * Evaluate Reverse Polish Notation
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Note:
 *
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't
 * be any divide by zero operation.
 *
 * Example 1:
 *
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 *
 * Explanation: ((2 + 1) * 3) = 9
 *
 * Example 2:
 *
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 *
 * Explanation: (4 + (13 / 5)) = 6
 *
 * Example 3:
 *
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 *
 * Explanation:
 *   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 */

#include <stack>
#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int evalRPN(std::vector<std::string> &tokens) {
    int size = tokens.size();
    if (size == 1) {
      return std::stoi(tokens[0]);
    }

    std::stack<int> st;
    for (int i = 0; i < size; i++) {
      if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
        st.push(std::stoi(tokens[i]));
      } else {
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();
        if (tokens[i] == "+") {
          st.push(num2 + num1);
        } else if (tokens[i] == "-") {
          st.push(num2 - num1);
        } else if (tokens[i] == "*") {
          st.push(num2 * num1);
        } else {
          st.push(num2 / num1);
        }
      }
    }
    return st.top();
  }

  static int helper(std::vector<std::string> &tokens, int &op) {
    std::string str = tokens[op];
    if (str != "+" && str != "-" && str != "*" && str != "/") {
      return std::stoi(str);
    }
    int num1 = helper(tokens, --op);
    int num2 = helper(tokens, --op);
    if (str == "+") {
      return num2 + num1;
    } else if (str == "-") {
      return num2 - num1;
    } else if (str == "*") {
      return num2 * num1;
    } else {
      return num2 / num1;
    }
  }
  static int evalRPN_recursion(std::vector<std::string> &tokens) {
    int op = tokens.size() - 1;
    return helper(tokens, op);
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> vec1 = {"2", "1", "+", "3", "*"};
  std::vector<std::string> vec2 = {"4", "13", "5", "/", "+"};
  std::vector<std::string> vec3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  if (Solution::evalRPN(vec1) != 9) {
    throw std::runtime_error("error 1");
  }
  if (Solution::evalRPN(vec2) != 6) {
    throw std::runtime_error("error 2");
  }
  if (Solution::evalRPN(vec3) != 22) {
    throw std::runtime_error("error 3");
  }
  if (Solution::evalRPN_recursion(vec1) != 9) {
    throw std::runtime_error("error 4");
  }
  if (Solution::evalRPN_recursion(vec2) != 6) {
    throw std::runtime_error("error 5");
  }
  if (Solution::evalRPN_recursion(vec3) != 22) {
    throw std::runtime_error("error 6");
  }

  return 0;
}
