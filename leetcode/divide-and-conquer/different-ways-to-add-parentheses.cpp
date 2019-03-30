//
// Created by Lu, Chih-chiang on 2019-01-13.
//

/**
 * Different Ways to Add Parentheses
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 *
 * Example 1:
 *
 * Input: "2-1-1"
 * Output: [0, 2]
 *
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 * Example 2:
 *
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 *
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static std::vector<int> diffWaysToCompute(std::string input) {
    std::vector<int> res;
    int n = input.size();
    for (int i = 0; i < n; ++i) {
      if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
        std::vector<int> left = diffWaysToCompute(input.substr(0, i));
        std::vector<int> right = diffWaysToCompute(input.substr(i + 1));
        int l = left.size(), r = right.size();
        for (int j = 0; j < l; ++j) {
          for (int k = 0; k < r; ++k) {
            if (input[i] == '+') {
              res.push_back(left[j] + right[k]);
            } else if (input[i] == '-') {
              res.push_back(left[j] - right[k]);
            } else {
              res.push_back(left[j] * right[k]);
            }
          }
        }
      }
    }
    if (res.empty()) {
      res.push_back(std::atoi(input.c_str()));
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<int> out1 = {2, 0};
  std::vector<int> out2 = {-34, -10, -14, -10, 10};
  if (Solution::diffWaysToCompute("2-1-1") != out1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::diffWaysToCompute("2*3-4*5") != out2) {
    throw std::runtime_error("error 2");
  }
  return 0;
}
