//
// Created by Lu, Chih-chiang on 2019-03-07.
//

/**
 * Restore IP Addresses
 *
 * Given a string containing only digits, restore it by returning
 * all possible valid IP address combinations.
 *
 * Example:
 *
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static void helper(std::string s, int n, std::string out, std::vector<std::string> &res) {
    if (n == 4 && s.empty()) {
      res.push_back(out);
      return;
    } else {
      for (int i = 1; i < 4; ++i) { // length of each field
        if (s.size() < i) {
          break;
        }
        int val = std::stoi(s.substr(0, i));
        if (val > 255 || i != std::to_string(val).size()) { // 0 in the beginning
          break;
        }
        helper(s.substr(i), n + 1, out + std::to_string(val) + (n == 3 ? "" : "."), res);
      }
    }
  }
  static std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string> res;
    if (s.size() <= 12) {
      helper(s, 0, "", res);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> out = {"255.255.11.135", "255.255.111.35"};
  if (Solution::restoreIpAddresses("25525511135") != out) {
    throw std::runtime_error("error");
  }
  return 0;
}
