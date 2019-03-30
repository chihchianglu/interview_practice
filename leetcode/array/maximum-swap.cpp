//
// Created by Lu, Chih-chiang on 2019-01-01.
//

/**
 * Maximum Swap
 *
 * Given a non-negative integer, you could swap two digits at most once to get the maximum valued number.
 * Return the maximum valued number you could get.
 *
 * Example 1:
 *
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 *
 * Example 2:
 *
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 */

#include <string>
#include <vector>
#include <stdexcept>

class Solution {
 public:
  static int maximumSwap_brute_force(int num) {
    std::string str = std::to_string(num);
    int res = num, n = str.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        std::swap(str[i], str[j]);
        res = std::max(res, std::stoi(str));
        std::swap(str[i], str[j]);
      }
    }
    return res;
  }
  static int maximumSwap(int num) {
    std::string str = std::to_string(num);
    std::vector<int> buckets(10, 0);

    for (int i = 0; i < str.size(); ++i) {
      buckets[str[i] - '0'] = i;
    }
    for (int i = 0; i < str.size(); ++i) {
      for (int j = 9; j > str[i] - '0'; --j) {
        if (buckets[j] <= i) {
          continue;
        }
        std::swap(str[i], str[buckets[j]]);
        return std::stoi(str);
      }
    }
    return num;
  }
};

int main(int argc, char *argv[]) {
  if (Solution::maximumSwap_brute_force(2736) != 7236) {
    throw std::runtime_error("error 1");
  }
  if (Solution::maximumSwap_brute_force(9973) != 9973) {
    throw std::runtime_error("error 2");
  }
  if (Solution::maximumSwap(2736) != 7236) {
    throw std::runtime_error("error 3");
  }
  if (Solution::maximumSwap(9973) != 9973) {
    throw std::runtime_error("error 4");
  }
  return 0;
}
