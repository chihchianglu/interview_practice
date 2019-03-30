//
// Created by Lu, Chih-chiang on 2019-03-06.
//

/**
 * Expression Add Operators
 *
 * Given a string that contains only digits 0-9 and a target value,
 * return all possibilities to add binary operators (not unary) +, -,
 * or * between the digits so they evaluate to the target value.
 *
 * Example 1:
 *
 * Input: num = "123", target = 6
 * Output: ["1+2+3", "1*2*3"]
 *
 * Example 2:
 *
 * Input: num = "232", target = 8
 * Output: ["2*3+2", "2+3*2"]
 *
 * Example 3:
 *
 * Input: num = "105", target = 5
 * Output: ["1*0+5","10-5"]
 *
 * Example 4:
 *
 * Input: num = "00", target = 0
 * Output: ["0+0", "0-0", "0*0"]
 *
 * Example 5:
 *
 * Input: num = "3456237490", target = 9191
 * Output: []
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  // 用递归来解题，我们需要两个变量diff和curNum，一个用来记录将要变化的值，另一个是当前运算后的值，而且它们都需要用 long 型的，
  // 因为字符串转为int型很容易溢出，所以我们用长整型。对于加和减，diff就是即将要加上的数和即将要减去的数的负值，而对于乘来说稍有些复杂，
  // 此时的diff应该是上一次的变化的diff乘以即将要乘上的数，有点不好理解，那我们来举个例子，比如 2+3*2，即将要运算到乘以2的时候，
  // 上次循环的 curNum = 5, diff = 3, 而如果我们要算这个乘2的时候，新的变化值diff应为 3*2=6，而我们要把之前+3操作的结果去掉，
  // 再加上新的diff，即 (5-3)+6=8，即为新表达式 2+3*2 的值
  static void helper(std::string num,
                     int target,
                     int64_t diff,
                     int64_t curNum,
                     std::string out,
                     std::vector<std::string> &res) {
    int n = num.size();
    if (n == 0 && curNum == target) {
      res.push_back(out);
      return;
    }
    for (int i = 1; i <= n; ++i) {
      std::string cur = num.substr(0, i);
      if (cur.size() > 1 && cur[0] == '0') {
        return;
      }
      std::string next = num.substr(i);
      if (out.empty()) {
        // this is the first number
        helper(next, target, std::stoll(cur), std::stoll(cur), cur, res);
      } else {
        // not the first number, let's add operators
        helper(next, target, std::stoll(cur), curNum + std::stoll(cur), out + "+" + cur, res); // +
        helper(next, target, -std::stoll(cur), curNum - std::stoll(cur), out + "-" + cur, res); // -
        helper(next,
               target,
               diff * std::stoll(cur),
               (curNum - diff) + diff * std::stoll(cur),
               out + "*" + cur,
               res); // *
      }
    }
  }
  static std::vector<std::string> addOperators(std::string num, int target) {
    std::vector<std::string> res;
    helper(num, target, 0, 0, "", res);
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> out_1 = {"1+2+3", "1*2*3"};
  std::vector<std::string> out_2 = {"2+3*2", "2*3+2"};
  std::vector<std::string> out_3 = {"1*0+5", "10-5"};
  std::vector<std::string> out_4 = {"0+0", "0-0", "0*0"};
  std::vector<std::string> out_5 = {};
  if (Solution::addOperators("123", 6) != out_1) {
    throw std::runtime_error("error 1");
  }
  if (Solution::addOperators("232", 8) != out_2) {
    throw std::runtime_error("error 2");
  }
  if (Solution::addOperators("105", 5) != out_3) {
    throw std::runtime_error("error 3");
  }
  if (Solution::addOperators("00", 0) != out_4) {
    throw std::runtime_error("error 4");
  }
  if (Solution::addOperators("3456237490", 9191) != out_5) {
    throw std::runtime_error("error 5");
  }
  return 0;
}
